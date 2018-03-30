cmake_minimum_required(VERSION 3.8)
project(sfmltest)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
set(CMAKE_CXX_STANDARD 14)
file(GLOB_RECURSE SOURCE_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)

# SFML
set(SFML_ROOT "lib/SFML/include")
find_package(SFML 2.4.2 COMPONENTS system window graphics audio network REQUIRED)
include_directories(${SFML_INCLUDE_DIR})

# FastNoise
include_directories(lib/FastNoise)

# SOURCES
include_directories(src)
add_executable(${PROJECT_NAME} ${SOURCE_FILES} lib/FastNoise/FastNoise.cpp)
#target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${SFML_SYSTEM_LIBRARY_DEBUG})
target_link_libraries(${PROJECT_NAME} ${SFML_WINDOW_LIBRARY_DEBUG})
target_link_libraries(${PROJECT_NAME} ${SFML_AUDIO_LIBRARY_DEBUG})
target_link_libraries(${PROJECT_NAME} ${SFML_NETWORK_LIBRARY_DEBUG})
target_link_libraries(${PROJECT_NAME} ${SFML_GRAPHICS_LIBRARY_DEBUG})


