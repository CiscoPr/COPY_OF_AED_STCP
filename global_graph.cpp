//
// Created by francisco on 26/01/22.
//

#include "global_graph.h"
#include <iostream>
#include "filereader.h"

filereader f2;

global_graph::global_graph(int stops, bool dir): n(stops), hasDir(dir), nodes(stops+1){}



void global_graph::addEdge(int src, int dest, int weight) {

}