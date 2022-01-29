#ifndef STCP_AED_PROJECT_DISTANCE_GRAPH_H
#define STCP_AED_PROJECT_DISTANCE_GRAPH_H
#include <vector>
#include <list>
#include <iostream>
#include <map>

class distance_graph {
    struct Edge{
        int dest;         /**<The integer associated with each stop*/
      //  int weight;       /**<Probabbly will be distance*/
        double distance;
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

    /**
     * constructor of this garph class
     * @param stops
     * @param dir
     */
    distance_graph(int stops, bool dir = true);
    /**
     * it reads the stops.csv file and associates each
     * part to variable
     */
    void stops();
    /**
     * it will define the edges of the graph
     */
    void edges();
    /**
     * this function will add each edge to the graph
     * @param src
     * @param dest
     * @param distance
     */
    void addEdge(int src, int dest, double distance);
    /**
     * this calculates the distance between two nodes
     * @param origin
     * @param destination
     * @return
     */
    int dijkstra_distance(int origin, int destination);
    /**
     * this will give us the shortest paths between
     * two nodes
     * @param origin
     * @param destination
     * @return
     */
    std::list<int> dijkstra_path(int origin, int destination);
    /**
     * using Dijkstra with MinHeap
     * @param s
     */
    void dijkstra(int s);
    /**
     * this will apply the Haversine formula to compute the distances
     * @param lat1
     * @param lon1
     * @param lat2
     * @param lon2
     * @return rad * c
     */
    double haversine(double lat1, double lon1, double lat2, double lon2);
    /**
     * given some coordinates by user input
     * this will get the closest stop
     * @param latitude
     * @param longitude
     * @return index
     */
    int closeststop(double latitude, double longitude);
    /**
     * unused, it's basically inside the mappers method
     * @param index
     * @return
     */
    std::string get_name(int index);
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


#endif //STCP_AED_PROJECT_DISTANCE_GRAPH_H