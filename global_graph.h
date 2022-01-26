//
// Created by francisco on 26/01/22.
//

#ifndef STCP_AED_PROJECT_GLOBAL_GRAPH_H
#define STCP_AED_PROJECT_GLOBAL_GRAPH_H
#include <vector>
#include <list>
class global_graph {
    struct Edge{
        int dest;         /**<The integer associated with each stop*/
        int weight;       /**<Probabbly will be distance*/
    };

    struct Node{
        std::list<Edge> adj;
    };

    int n;        /**<Number of stops*/
    bool hasDir;
    std::vector<Node> stops;    /**<The list of nodes/stops being represented*/

public:

    global_graph(int stops, bool dir = true);
    void addEdge(int src, int dest, int weight);
};


#endif //STCP_AED_PROJECT_GLOBAL_GRAPH_H
