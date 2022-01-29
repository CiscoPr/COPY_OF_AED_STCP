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
    void addEdge(int src, int dest);
    //int dijkstra_distance(int origin, int destination);
   // std::list<int> dijkstra_path(int origin, int destination);
    //void dijkstra(int s)
    // ;
    /**
     * in this case, it will only be used
     * for us to get the closest stop to the
     * user's coordinates
     * it is useless for the rest of the graph,
     * since it's unweighted
     * @param lat1
     * @param lon1
     * @param lat2
     * @param lon2
     * @return
     */
    double haversine(double lat1, double lon1, double lat2, double lon2);
    std::stack<int> shortest_path(int s, int d);
    /**
     * given some coordinates by user input
     * this will get the closest stop
     * @param latitude
     * @param longitude
     * @return index
     */
    int closeststop(double latitude, double longitude);
    /**
     * this will get the index of a
     * given stop code
     * @param stop
     * @return
     */
    int get_index(std::string stop);
    /**
     * gets the name of the stop
     * @param a
     * @return name
     */
    std::string mappers(int a);
};

#endif
