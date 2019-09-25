cmake_minimum_required(VERSION 3.14)
project(ElepthicPoint)

set (CMAKE_CXX_FLAGS "-fexceptions -Wall")

set(CMAKE_CXX_STANDARD 17)

add_executable(ElepthicPoint main.cpp Field.cpp Field.h BigInt.cpp BigInt.h IntegerMod.cpp IntegerMod.h Exeptions.h Logger.cpp Logger.h EllipticCurve.cpp EllipticCurve.h Rand.cpp Rand.h)


#set(GTEST "C:/GoogleTest")

#include_directories(Test ${GTEST}/googletest/include)
#add_subdirectory(Test ${GTEST})
#add_executable(Test test/test.cpp)
#target_link_libraries(Test ${GTEST}/build/lib/Release/gtest.lib ${GTEST}/build/lib/Release/gtest_main.lib)
