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
     * unused
     * @param filename
     */
    std::vector<std::string> readlinescsv(std::string filename);
    /**
     * this will create the map which associates each stop code
     * with a different integer
     * @param file
     * @param n
     * @param stops_map
     * @return
     */
    std::map<std::string, int> stops_code(std::ifstream &file, int n,std::map<std::string, int> &stops_map);
    /**
     * unused
     * @return
     */
    std::map<std::string, int> readstops();
    /**
     * this function will get the total number of
     * stops
     * @return number_of_stops
     */
    int number_of_stops();
    /**
     * this will associate a part of the line
     * to the name of the stop
     * @param file
     * @return
     */
    std::string stops_name(std::ifstream &file);
    /**
     * this will associate a part of the line
     * to the zone of the stop
     * @param file
     * @return
     */
    std::string stops_zone(std::ifstream &file);
    /**
     * this will associate a part of the line
     * to the latitude of the stop
     * @param file
     * @return
     */
    double stops_latitude(std::ifstream &file);
    /**
     * this will associate a part of the line
     * to the longitude of the stop
     * @param file
     * @return
     */
    double stops_longitude(std::ifstream &file);
    /**
     * this returns a vector with all the lines
     * in the file
     * @return
     */
    std::vector<std::string> lines();
    /**
     * this associates each line of the file
     * to a stop
     * @param filename
     * @return
     */
    std::string stops(std::ifstream &filename);
};


#endif //STCP_AED_PROJECT_FILEREADER_H
