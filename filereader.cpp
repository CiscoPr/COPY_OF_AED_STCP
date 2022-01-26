//
// Created by francisco on 25/01/22.
//
#include "filereader.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
void filereader::readlinescsv(std::string filename) {
    std::string code, name, line, skiiiiiiiiiiip;
    std::string path = "../dataset/"+ filename;
    std::ifstream linesfile{path};

    if(!linesfile.is_open())
        std::cout << filename << " doesn't exist!";
    getline(linesfile, skiiiiiiiiiiip);
    while (getline(linesfile, line)){
        std::stringstream ss(line);
        std::string code;
        getline(ss, code, ',');

        std::string name;
        getline(ss, name);
        std::cout << "Your line's name is: " << name << '\n';

    }
    linesfile.close();
}


void filereader::readstops() {
    std::map<std::string, int> mapping_stops;
    /*
    std::string filename = "../dataset/line_" + std::to_string(code) + "_" + std::to_string(direction)+".csv";
    std::ifstream stopsfile{filename};
    int i = 0;
    std::string skiiiiiiiiiiip, line;
    if(!stopsfile.is_open())
        std::cout << filename << " doesn't exist!";
    getline(stopsfile, skiiiiiiiiiiip);
    while (getline(stopsfile, line)){
        i++;
        std::stringstream ss(line);
        std::string stop;
        getline(ss, stop);
        if(i == 1)
            std::cout << "On this line, the " + std::to_string(i) +"st stop is: " + stop+ '\n';
        else if(i == 2)
            std::cout << "On this line, the " + std::to_string(i) +"nd stop is: " + stop+ '\n';
        else if(i==3)
            std::cout << "On this line, the " + std::to_string(i) +"rd stop is: " + stop+ '\n';
        else
            std::cout << "On this line, the " + std::to_string(i) +"th stop is: " + stop+ '\n';
    }
    stopsfile.close();
     */
    std::string filename = "../dataset/stops.csv";
    std::ifstream stops_file{filename};
    std::string first_line, line;
    if (!stops_file.is_open())
        std::cout << filename << " doesn't exist!";
    getline(stops_file, first_line);
    int i = 0;
    while (getline(stops_file, line)) {
        i++;
        std::stringstream ss(line);
        std::string code;
        std::getline(ss, code, ',');
        mapping_stops[code] = i;
        std::string name;
        std::getline(ss, name, ',');
        std::string zone;
        std::getline(ss, zone, ',');
        std::string latitude;
        std::getline(ss, latitude, ',');
        std::string longitude;
        std::getline(ss, longitude);
        //ss >> code >> name >> zone >> latitude >> longitude;
        std::cout << code << " " << name << " " << zone << " " << latitude << " " << longitude << '\n';

    }
    stops_file.close();
}


void filereader::associatestops() {

}