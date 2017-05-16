cmake_minimum_required(VERSION 3.6)
project(Tarea1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Geometry/Point.h Geometry/JVector.h Geometry/Segmento.h Geometry/Polygon.h Algorithms/GiftWrapping.cpp Algorithms/GiftWrapping.h Algorithms/QuickHull.cpp Algorithms/QuickHull.h Algorithms/ConvexHullAlgorithm.cpp Algorithms/ConvexHullAlgorithm.h Generators/CirclePointsGenerator.cpp Generators/CirclePointsGenerator.h Generators/RandomPointsGenerator.cpp Generators/RandomPointsGenerator.h)
add_executable(Tarea1 ${SOURCE_FILES})