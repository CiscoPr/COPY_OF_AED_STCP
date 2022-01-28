#ifndef STCP_AED_PROJECT_FILEREADER_H
#define STCP_AED_PROJECT_FILEREADER_H
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "distance_graph.h"
class filereader {
public:
    /**
     *
     * @param filename
     */
    std::vector<std::string> readlinescsv(std::string filename);
    /**
     *
     * @param code
     * @param direction
     */
    std::map<std::string, int> stops_code(std::ifstream &file, int n,std::map<std::string, int> &stops_map);
    std::map<std::string, int> readstops();
    int number_of_stops();
    std::string stops_name(std::ifstream &file);
    std::string stops_zone(std::ifstream &file);
    double stops_latitude(std::ifstream &file);
    double stops_longitude(std::ifstream &file);
    std::vector<std::string> lines();
    std::string stops(std::ifstream &filename);
};


#endif //STCP_AED_PROJECT_FILEREADER_H
