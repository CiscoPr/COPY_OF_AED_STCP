#include "lesschanges_graph.h
#include "distance_graph.h"
#include <iostream>
#include <fstream>
#include "filereader.h"
#include <cmath>
#include <climits>
#include "minHeap.h"
#include "lesschanges_graph.h"
#include <queue>
#include <vector>
#include <stack>
#define INF (INT_MAX/2)
filereader f3;

lesschanges_graph::lesschanges_graph(int stops, bool dir): n(stops), hasDir(dir), nodes(stops + 1){}

void lesschanges_graph::stops() {
    int n = f3.number_of_stops();
    std::string filename = "../dataset/stops.csv";
    std::string first_line;
    std::ifstream stops;
    stops.open(filename);
    if(!stops.is_open()){
        std::cout << filename << " doesn't exist!";
    }
    getline(stops,first_line);
    for(int i=1;i<=n;i++){
        map_stops=f3.stops_code(stops,i,map_stops);
        nodes[i].name=f3.stops_name(stops);
        nodes[i].zone=f3.stops_zone(stops);
        nodes[i].latitude=f3.stops_latitude(stops);
        nodes[i].longitude=f3.stops_longitude(stops);
    }
    stops.close();
}

void lesschanges_graph::addEdge(int src, int dest) {
    if (src<1 || src>n || dest<1 || dest>n) return;
    nodes[src].adj.push_back({dest});
    if (!hasDir) nodes[dest].adj.push_back({src});
}

void lesschanges_graph::edges() {
    std::vector<std::string> codes;
    std::string string_n, line, first_stop, second_stop;
    double distance;
    int n, node, node_1, node_2;
    codes = f3.lines();
    for (int i = 0; i < codes.size(); i++) {
        std::string filename = "../dataset/line_" + codes[i] + "_0.csv";
        std::ifstream edges{filename};
        getline(edges, string_n);
        line = f3.stops(edges);
        n = stoi(string_n);
        for (int i = 2; i < n + 1; i++) {                                //if something goes wrong, we should check here
            first_stop = line;
            second_stop = f3.stops(edges);
            line = second_stop;
            node_1 = map_stops[first_stop];
            node_2 = map_stops[second_stop];
           // distance = haversine(nodes[node_1].latitude, nodes[node_1].longitude, nodes[node_2].latitude,nodes[node_2].longitude);
            addEdge(node_1, node_2);
        }
        edges.close();
    }

    for (int i = 0; i < codes.size(); i++) {
        std::string filename = "../dataset/line_" + codes[i] + "_1.csv";
        std::ifstream edges{filename};
        getline(edges, string_n);
        line = f3.stops(edges);
        n = stoi(string_n);
        for (int i = 2;i < n + 1; i++) {                                //if something goes wrong, we should check here
            first_stop = line;
            second_stop = f3.stops(edges);
            line = second_stop;
            node_1 = map_stops[first_stop];
            node_2 = map_stops[second_stop];
            //distance = haversine(nodes[node_1].latitude, nodes[node_1].longitude, nodes[node_2].latitude,nodes[node_2].longitude);
            addEdge(node_1, node_2);
        }
        edges.close();
    }
}
double lesschanges_graph::haversine(double lat1, double lon1, double lat2, double lon2) {
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

int lesschanges_graph::get_index(std::string stop) {
    int index;
    index = map_stops[stop];
    return index;
}


int lesschanges_graph::closeststop(double latitude, double longitude) {
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


void lesschanges_graph::bfs(int start, int end){

    queue<int> q;
    for(int v = 1; v <= n; v++){
        nodes[v].visited = false;
        nodes[v].pred = -1;
    }
    q.push(start);
    nodes[start].visited = true;
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        for(auto k: nodes[temp].adj){
            int w = k.dest;
            if(nodes[w].visited == false){
                q.push(w);
                nodes[w].visited = true;
                nodes[w].pred = temp;
            }
        }
    }
}

stack<int> lesschanges_graph::shortest_path(int s, int d) {
    bfs(s,d);
    stack<int> st;
    while(nodes[d].pred != -1){
        st.push(d);
        d = nodes[d].pred;
    }
    return st;
}




std::string lesschanges_graph::mappers(int a) {
    string name = nodes[a].name;
    return name;
}



/*
void lesschanges_graph::stops(){
    int n=f1.number_of_stops();
    std::string filename = "../dataset/stops.csv";
    std::ifstream stops;
    stops.open(filename);
    if(!stops.is_open()){
        std::cout << filename << " doesn't exist!";
    }
    for(int i=1;i<=n;i++){
        map_stops=f1.stops_code(stops,n,map_stops);
        nodes[i].name=f1.stops_name(stops);
        nodes[i].zone=f1.stops_zone(stops);
        nodes[i].latitude=f1.stops_latitude(stops);
        nodes[i].longitude=f1.stops_longitude(stops);
    }
    stops.close();
}

void lesschanges_graph::addEdge(int src, int dest, double distance) {
    if (src<1 || src>n || dest<1 || dest>n) return;
    nodes[src].adj.push_back({dest, distance});
    if (!hasDir) nodes[dest].adj.push_back({src, distance};
}

void lesschanges_graph::edges() {
    std::vector<std::string> codes;
    std::string string_n, line, first_stop, second_stop;
    double distance;
    int n, node, node_1, node_2;
    codes = f1.lines();
    for (int i = 0; i < codes.size(); i++) {
        std::string filename = "../dataset/line_" + codes[i] + "_0.csv";
        std::ifstream edges{filename};
        getline(edges, string_n);
        line = f1.stops(edges);
        n = stoi(string_n);
        for (int i = 2;
             i <= n + 1; i++) {                                //if something goes wrong, we should check here
            first_stop = line;
            second_stop = f1.stops(edges);
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
        line = f1.stops(edges);
        n = stoi(string_n);
        for (int i = 2;
             i <= n + 1; i++) {                                //if something goes wrong, we should check here
            first_stop = line;
            second_stop = f1.stops(edges);
            line = second_stop;
            node_1 = map_stops[first_stop];
            node_2 = map_stops[second_stop];
            distance = haversine(nodes[node_1].latitude, nodes[node_1].longitude, nodes[node_2].latitude,
                                 nodes[node_2].longitude);
            addEdge(node_1, node_2, distance);
        }
        edges.close();
    }
}

double lesschanges_graph::haversine(double lat1, double lon1, double lat2, double lon2){
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


int lesschanges_graph::dijkstra_distance(int origin, int destination) {
    dijkstra(origin);
    if(nodes[destination].dist == INT_MAX) return -1;
    return nodes[destination].dist;
}

std::list<int> lesschanges_graph::dijkstra_path(int origin, int destination) {
    dijkstra(origin);
    std::list<int> path;
    if(nodes[destination].dist == INT_MAX) return path;
    path.push_back(destination);
    int v = destination;
    while(v != origin){
        v = nodes[v].pred;
        path.push_front(v);
    }
    return path;

}


void lesschanges_graph::dijkstra(int s) {
    MinHeap<int, int> q(n, -1);
    for (int v= 1; v <= n; v++){
        nodes[v].dist = INT_MAX;
        q.insert(v, INT_MAX);
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
            int w = edge.distance;
            if(!nodes[u].visited && nodes[u].dist + w < nodes[v].dist){
                nodes[v].dist = nodes[u].dist + w;
                q.decreaseKey(v, nodes[v].dist);
                nodes[v].pred = u;
            }
        }
    }
}
*/
