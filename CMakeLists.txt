cmake_minimum_required(VERSION 3.24)
project(projekt_SDiZO_2)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_BUILD_TYPE "Release")

set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} "-static")

add_executable(projekt_SDiZO_2 main.cpp graph/GraphAsList.cpp graph/GraphAsList.h graph/GraphAsMatrix.cpp graph/GraphAsMatrix.h utilities/FileOperator.cpp utilities/FileOperator.h algorithms/Kruskal.cpp algorithms/Kruskal.h algorithms/Prim.cpp algorithms/Prim.h algorithms/Dijkstra.cpp algorithms/Dijkstra.h algorithms/BellmanFord.cpp algorithms/BellmanFord.h utilities/DisjointSets.cpp utilities/DisjointSets.h utilities/Timer.cpp utilities/Timer.h testers/ManualTester.cpp testers/ManualTester.h testers/AutomaticTester.cpp testers/AutomaticTester.h)
