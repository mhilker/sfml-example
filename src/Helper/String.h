#ifndef SFMLTEST_STRING_H
#define SFMLTEST_STRING_H

#include <sstream>
#include <string>

template <typename T>
std::string to_string(T value)
{
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

#endif //SFMLTEST_STRING_H
