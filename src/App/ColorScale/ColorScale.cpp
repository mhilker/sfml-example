/*
 *  ColorScale.cpp
 *
 *  Created by mooglwy on 31/10/10.
 *
 *  This software is provided 'as-is', without any express or
 *  implied warranty. In no event will the authors be held
 *  liable for any damages arising from the use of this software.
 *
 *  Permission is granted to anyone to use this software for any purpose,
 *  including commercial applications, and to alter it and redistribute
 *  it freely, subject to the following restrictions:
 *
 *  1. The origin of this software must not be misrepresented;
 *     you must not claim that you wrote the original software.
 *     If you use this software in a product, an acknowledgment
 *     in the product documentation would be appreciated but
 *     is not required.
 *
 *  2. Altered source versions must be plainly marked as such,
 *     and must not be misrepresented as being the original software.
 *
 *  3. This notice may not be removed or altered from any
 *     source distribution.
 *
 */

#include "ColorScale.h"
#include <iostream>

const double PI = 3.1415926535;

double linearInterpolation(double v1, double v2, double mu)
{
    return v1*(1-mu)+v2*mu;
}

double interpolateCosinus(double y1, double y2, double mu)
{
    double mu2;

    mu2 = (1-cos(mu*PI))/2;
    return y1*(1-mu2)+y2*mu2;
}

ColorScale::ColorScale() = default;

bool ColorScale::insert(double position, sf::Color color)
{
    std::pair< ColorScale::iterator,bool > ret = std::map<double,sf::Color>::insert(std::make_pair(position,color));
    return ret.second;
}

double ABS(double a) {
        return std::max(a, 0.d);
}

void ColorScale::fillTab(sf::Color* colorTab, int size, InterpolationFunction::InterpolationFunction function)
{

    ColorScale::const_iterator start = std::map<double,sf::Color>::begin();
    ColorScale::const_iterator last  = std::map<double,sf::Color>::end();
    last--;

    double pos = 0.0;
    double distance = last->first - start->first;
    ColorScale::const_iterator it =  start;

    double(*pFunction)(double,double,double);

    switch (function)
    {
        case InterpolationFunction::Cosinus:
            pFunction = interpolateCosinus;
            break;
        case InterpolationFunction::Linear :
            pFunction = linearInterpolation;
            break;
        default:
            pFunction = interpolateCosinus;
            break;

    }

    while(it != last)
    {
        sf::Color startColor = it->second;
        double    startPos   = it->first;
        it++;
        sf::Color endColor   = it->second;
        double    endPos     = it->first;
        double nb_color      = ((endPos - startPos) * (double)size / distance);

        for(int i = (int)pos; i <= (int)(pos + nb_color); i++)
        {
            colorTab[i].r = (unsigned char)pFunction(startColor.r, endColor.r, ABS((double)i - pos) / (nb_color - 1.0));
            colorTab[i].g = (unsigned char)pFunction(startColor.g, endColor.g, ABS((double)i - pos) / (nb_color - 1.0));
            colorTab[i].b = (unsigned char)pFunction(startColor.b, endColor.b, ABS((double)i - pos) / (nb_color - 1.0));
            colorTab[i].a = (unsigned char)pFunction(startColor.a, endColor.a, ABS((double)i - pos) / (nb_color - 1.0));
        }
        pos += nb_color;
    }

}
