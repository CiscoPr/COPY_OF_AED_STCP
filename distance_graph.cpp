#include "distance_graph.h"
#include <iostream>
#include <fstream>
#include "filereader.h"
#include <cmath>
#include <climits>
#include "minHeap.h"
#define INF (INT_MAX/2)

filereader f2;



distance_graph::distance_graph(int stops, bool dir): n(stops), hasDir(dir), nodes(stops + 1){}

void distance_graph::stops(){
    int n=f2.number_of_stops();
    std::string filename = "../dataset/stops.csv";
    std::string first_line;
    std::ifstream stops;
    stops.open(filename);
    if(!stops.is_open()){
        std::cout << filename << " doesn't exist!";
    }
    getline(stops,first_line);
    for(int i=1;i<=n;i++){
        map_stops=f2.stops_code(stops,i,map_stops);
        nodes[i].name=f2.stops_name(stops);
        nodes[i].zone=f2.stops_zone(stops);
        nodes[i].latitude=f2.stops_latitude(stops);
        nodes[i].longitude=f2.stops_longitude(stops);
    }
    stops.close();
}
void distance_graph::addEdge(int src, int dest, double distance) {
    if (src<1 || src>n || dest<1 || dest>n) return;
    nodes[src].adj.push_back({dest, distance});
    if (!hasDir) nodes[dest].adj.push_back({src, distance});
}
void distance_graph::edges() {
    std::vector<std::string> codes;
    std::string string_n, line, first_stop, second_stop;
    double distance;
    int n, node, node_1, node_2;
    codes = f2.lines();
    for (int i = 0; i < codes.size(); i++) {
        std::string filename = "../dataset/line_" + codes[i] + "_0.csv";
        std::ifstream edges{filename};
        getline(edges, string_n);
        line = f2.stops(edges);
        n = stoi(string_n);
        for (int i = 2; i < n + 1; i++) {                                //if something goes wrong, we should check here
            first_stop = line;
            second_stop = f2.stops(edges);
            line = second_stop;
            node_1 = map_stops[first_stop];
            node_2 = map_stops[second_stop];
            distance = haversine(nodes[node_1].latitude, nodes[node_1].longitude, nodes[node_2].latitude,
                                 nodes[node_2].longitude);
            addEdge(node_1, node_2, distance);
        }
        edges.close();
    }
    for (int i = 0; i < codes.size(); i++) {
        std::string filename = "../dataset/line_" + codes[i] + "_1.csv";
        std::ifstream edges{filename};
        getline(edges, string_n);
        line = f2.stops(edges);
        n = stoi(string_n);
        for (int i = 2;i < n + 1; i++) {                                //if something goes wrong, we should check here
            first_stop = line;
            second_stop = f2.stops(edges);
            line = second_stop;
            node_1 = map_stops[first_stop];
            node_2 = map_stops[second_stop];
            distance = haversine(nodes[node_1].latitude, nodes[node_1].longitude, nodes[node_2].latitude,nodes[node_2].longitude);
            addEdge(node_1, node_2, distance);
        }
        edges.close();
    }
}

double distance_graph::haversine(double lat1, double lon1, double lat2, double lon2){
    // distance between latitudes
    // and longitudes
    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLon = (lon2 - lon1) * M_PI / 180.0;

    // convert to radians
    lat1 = (lat1) * M_PI / 180.0;
    lat2 = (lat2) * M_PI / 180.0;

    // apply formulae
    double a = pow(sin(dLat / 2), 2) + pow(sin(dLon / 2), 2) * cos(lat1) * cos(lat2);
    double rad = 6371;
    double c = 2 * asin(sqrt(a));
    return rad * c;
}


int distance_graph::dijkstra_distance(int origin, int destination) {
    dijkstra(origin);
    if(nodes[destination].dist == INF) return -1;
    std::cout << nodes[destination].dist;
    return nodes[destination].dist;
}


std::list<int> distance_graph::dijkstra_path(int origin, int destination) {
    dijkstra(origin);
    std::list<int> path;
    if(nodes[destination].dist == INF) return path;
    path.push_back(destination);
    int v = destination;
    while(v != origin){
        v = nodes[v].pred;
        path.push_front(v);
    }
    return path;
}


void distance_graph::dijkstra(int s) {
    MinHeap<int, double> q(n, -1);
    for (int v= 1; v <= n; v++){
        nodes[v].dist = INF;
        q.insert(v, INF);
        nodes[v].visited = false;
    }
    nodes[s].dist = 0;
    q.decreaseKey(s,0);
    nodes[s].pred = s;
    while(q.getSize() > 0){
        int u = q.removeMin();
        nodes[u].visited = true;
        for(auto edge: nodes[u].adj){
            int v = edge.dest;
            double w = edge.distance;
            if(!nodes[v].visited && nodes[u].dist + w < nodes[v].dist){
                nodes[v].dist = nodes[u].dist + w;
                q.decreaseKey(v, nodes[v].dist);
                nodes[v].pred = u;
            }
        }
    }
}
std::string distance_graph::get_name(int index){
    std::string name;
    name=nodes[index].name;
    return name;
}
int distance_graph::get_index(std::string stop){
    int index;
    index=map_stops[stop];
    return index;
}
int distance_graph::closeststop(double latitude, double longitude){
    int index;
    double distance;
    double min_dist = INF;
    for (int i=1; i<nodes.size();i++){
        distance=haversine(latitude,longitude,nodes[i].latitude,nodes[i].longitude);
        if(distance<min_dist){
            min_dist=distance;
            index=i;
        }
    }
    return index;
}
std::string distance_graph::mappers(int a){
    string name=nodes[a].name;
    return name;
}