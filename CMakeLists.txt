cmake_minimum_required(VERSION 3.5)

project(settime VERSION 0.1)

#set(MINGW64_NT-10.0-17763)

#set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -lstdc++ -lgcc"  )
#set(CMAKE_POSITION_INDEPENDENT_CODE ON)
#add_definitions(-msys)
#add_definitions(-mingw64)

add_executable(${PROJECT_NAME} main.cpp)