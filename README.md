sudo apt-get install libpthread-stubs0-dev
sudo apt-get install libgl1-mesa-dev
sudo apt-get install libx11-dev
sudo apt-get install libxrandr-dev
sudo apt-get install libfreetype6-dev
sudo apt-get install libglew1.5-dev
sudo apt-get install libjpeg8-dev
sudo apt-get install libsndfile1-dev
sudo apt-get install libopenal-dev
sudo apt-get install cmake
sudo apt-get install g++

curl https://gitlab.peach-bun.com/pinion/SFML/commit/3383b4a472f0bd16a8161fb8760cd3e6333f1782.patch | git apply

cmake -G"Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -DBUILD_SHARED_LIBS=TRUE
cmake -G"Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug -DBUILD_SHARED_LIBS=TRUE
cmake -G"Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -DBUILD_SHARED_LIBS=FALSE
cmake -G"Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug -DBUILD_SHARED_LIBS=FALSE

make
make install
