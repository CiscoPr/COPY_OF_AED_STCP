//
// Created by francisco on 25/01/22.
//

#ifndef STCP_AED_PROJECT_FILEREADER_H
#define STCP_AED_PROJECT_FILEREADER_H
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "global_graph.h"
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
    std::map<std::string, int> readstops();
    int number_of_stops();

};


#endif //STCP_AED_PROJECT_FILEREADER_H
