//
// Created by francisco on 25/01/22.
//

#ifndef STCP_AED_PROJECT_FILEREADER_H
#define STCP_AED_PROJECT_FILEREADER_H
#include <iostream>
#include <string>

class filereader {
public:
    /**
     *
     * @param filename
     */
    void readlinescsv(std::string filename);
    /**
     *
     * @param code
     * @param direction
     */
    void readstops(int code, int direction);
    void associating();
};


#endif //STCP_AED_PROJECT_FILEREADER_H
