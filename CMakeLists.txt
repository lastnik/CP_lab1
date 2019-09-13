cmake_minimum_required(VERSION 3.14)
project(ElepthicPoint)

set (CMAKE_CXX_FLAGS "-fexceptions -Werror -Wall -Wextra")

set(CMAKE_CXX_STANDARD 17)

add_executable(ElepthicPoint main.cpp Field.cpp Field.h BigInt.cpp BigInt.h IntegerMod.cpp IntegerMod.h Exeptions.h Logger.cpp Logger.h JsonParser.cpp JsonParser.h)