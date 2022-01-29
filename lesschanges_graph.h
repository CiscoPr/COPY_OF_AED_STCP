#ifndef STCP_AED_PROJECT_LESSCHANGES_GRAPH_H
#define STCP_AED_PROJECT_LESSCHANGES_GRAPH_H

#include <list>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stack>

class lesschanges_graph {
    struct Edge{
        int dest;         /**<The integer associated with each stop*/
        //int weight;       /**<Probabbly will be distance*/
    };

    struct Node{
        std::list<Edge> adj;
        int dist;
        int pred;
        std::string name;
        std::string zone;
        double longitude;
        double latitude;
        bool visited;
    };

    int n;        /**<Number of stops*/
    bool hasDir;
    std::vector<Node> nodes;    /**<The list of nodes/stops being represented*/
    std::map<std::string, int> map_stops;
public:

    lesschanges_graph(int stops, bool dir = true);
    void bfs(int start, int end);
    void stops();
    void edges();
    void addEdge(int src, int dest, double distance);
    //int dijkstra_distance(int origin, int destination);
   // std::list<int> dijkstra_path(int origin, int destination);
    //void dijkstra(int s);
    double haversine(double lat1, double lon1, double lat2, double lon2);
    std::stack<int> print_path(int s, int d);
};

#endif
