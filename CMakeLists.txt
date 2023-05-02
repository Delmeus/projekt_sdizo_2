cmake_minimum_required(VERSION 3.24)
project(projekt_SDiZO_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(projekt_SDiZO_2 main.cpp graph/GraphAsList.cpp graph/GraphAsList.h graph/GraphAsMatrix.cpp graph/GraphAsMatrix.h utilities/FileCreator.cpp utilities/FileCreator.h algorithms/Kruskal.cpp algorithms/Kruskal.h algorithms/Prim.cpp algorithms/Prim.h algorithms/Dijkstra.cpp algorithms/Dijkstra.h algorithms/BellmanFord.cpp algorithms/BellmanFord.h utilities/DisjointSets.cpp utilities/DisjointSets.h utilities/Timer.cpp utilities/Timer.h testers/ManualTester.cpp testers/ManualTester.h testers/AutomaticTester.cpp testers/AutomaticTester.h)
