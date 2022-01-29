#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <fstream>
#include <sstream>
#include "filereader.h"
#include "distance_graph.h"
#include "lesschanges_graph.h"
#include <climits>
#include <cmath>

//! this will be the function with the menu_trip
int main() {
    int option;
    filereader f1;
    char ch = ' ';
    std::cout << "                 /############.                                                                     \n"
                 "             ,####################                                                                  \n"
                 "           /#####(            ######.                                                               \n"
                 "          #####                 .#####                                                              \n"
                 "      .*******.                  /#######            #######(  #########/   (########  #########    \n"
                 "    .***********.              (###########         ###(          ###/    .###.        ###,  (###   \n"
                 "    ****     ****              ####     ###(         *#######     ###/    ###(         #########    \n"
                 "    .*****.*****.              #####/,#####               ###,    ###/     ###(        ###,         \n"
                 "      ,********                  ########,          (#######      ###/       ########  ###,         \n"
                 "          *****.                ,****,                                                              \n"
                 "           .******            ******                                                                \n"
                 "              ********************                                                                  \n"
                 "                  ***********.                                                                      \n"
                 "                                                                                                    \n"
                 "                                 Please, hold ENTER to advance . . ."<< std::endl;
    std::cin.get();
    std::cout << std::string(100, '\n');
    std::cout << "                                 Welcome to STCP!                                                  \n"
                 "                               How can we help you?                                                \n"
                 "                                                                                                   \n"
                 "                           1-get the shortest path                                                 \n"
                 "                           2-get the trip with less bus changes                                    \n"
                 "                           3-get the distance between me and a certain stop                        \n"
                 "                           4-exit                                                                  "<< std::endl;
    std::cout << std::string(4, '\n');
    std::cout << "                           Please enter your choice: ";
    std::cin >> option;
    if(option == 1){
        std::list<int> path1;
        std::list<int>::iterator it;
        int index, destination_index;
        double latitude, longitude;
        std::string destination,stop;
        std::cout << '\n';
        std::cout << "                       Where are you at the moment? Put                                        \n"
                     "                       latitude in here! ";
        std::cin >> latitude;
        std::cout << '\n';
        std::cout << "                       And put longitude in here! ";
        std::cin  >> longitude;
        std::cout << '\n';
        std::cout << "                       To what stop do you wish to go? Put                                     \n"
                     "                       its code in here! ";
        std::cin >> destination;
        std::cout << '\n';
        distance_graph graph= distance_graph(f1.number_of_stops(),true);
        graph.stops();
        graph.edges();
        index=graph.closeststop(latitude,longitude);
        destination_index=graph.get_index(destination);
        path1=graph.dijkstra_path(index,destination_index);
        for(it=path1.begin(); it!= path1.end();it++){
            int stop= *it;
            std::cout<<graph.mappers(stop)<<"\n";
        }
    }
    if(option == 2){
        std::stack<int> path2;
        std::list<int>::iterator it1;
        int index1, destination_index1;
        double latitude1, longitude1;
        std::string destination1, stop;
        std::cout << '\n';
        std::cout << "                       Where are you at the moment? Put                                        \n"
                     "                       latitude in here! ";
        std::cin >> latitude1;
        std::cout << '\n';
        std::cout << "                       And put longitude in here! ";
        std::cin  >> longitude1;
        std::cout << '\n';
        std::cout << "                       To what stop do you wish to go? Put                                     \n"
                     "                       its code in here! ";
        std::cin >> destination1;
        std::cout << '\n';
        lesschanges_graph graph1 = lesschanges_graph(f1.number_of_stops(), true);
        graph1.stops();
        graph1.edges();
        index1 = graph1.closeststop(latitude1, longitude1);
        destination_index1 = graph1.get_index(destination1);
        path2 = graph1.shortest_path(index1, destination_index1);
        while(!path2.empty()){
            int stop1 = path2.top();
            std::cout << graph1.mappers(stop1) << '\n';
            path2.pop();
        }
        //f1.readstops();

    }

    if(option == 3){
        int index2, destination_index2, pos = 0;
        double latitude2, longitude2, latitude_of_d, longitude_of_d;
        std::string destination2, first_line, line2;
        std::cout << '\n';
        std::cout << "                       Where are you at the moment? Put                                        \n"
                     "                       latitude in here! ";
        std::cin >> latitude2;
        std::cout << '\n';
        std::cout << "                       And put longitude in here! ";
        std::cin  >> longitude2;
        std::cout << '\n';
        std::cout << "                       Please put the code of the stop                                         \n"
                     "                       here: ";
        std::cin >> destination2;
        std::cout << '\n';
        std::string stops_file = "../dataset/stops.csv";
        std::ifstream most_useful_feature_ever{stops_file};
        while(std::getline(most_useful_feature_ever, line2))
        {
            std::stringstream ss(line2);
            std::string code;
            std::getline(ss, code, ',');
            std::string name;
            std::getline(ss, name, ',');
            std::string zone;
            std::getline(ss, zone, ',');
            std::string latitude4;
            std::getline(ss, latitude4, ',');
            std::string longitude4;
            std::getline(ss, longitude4);
            ss >> code >> name >> zone >> latitude4 >> longitude4;
            if(destination2 == code) {
                latitude_of_d = std::stod(latitude4);
                longitude_of_d = std::stod(longitude4);
                break;
            }

        }
        most_useful_feature_ever.close();
        //std::cout << latitude_of_d << "\n";
        //std::cout << longitude_of_d << "\n";
        //now we shall apply the haversine formula
        // distance between latitudes
        // and longitudes
        double dLat = (latitude_of_d - latitude2) * M_PI / 180.0;
        double dLon = (longitude_of_d - longitude2) * M_PI / 180.0;

        // convert to radians
        latitude2 = (latitude2) * M_PI / 180.0;
        latitude_of_d = (latitude_of_d) * M_PI / 180.0;

        // apply formulae
        double a = pow(sin(dLat / 2), 2) + pow(sin(dLon / 2), 2) * cos(latitude2) * cos(latitude_of_d);
        double rad = 6371;
        double c = 2 * asin(sqrt(a));
        double result = rad * c;
        std::cout << "                       You're currently " << result << "km away from the stop!";
        //f1.readstops();

    }
    if(option == 4){
        std::cout << std::string(4, '\n');
        std::cout << "                        Are you sure you want to quit? [y/n] ";
        std::cin >> ch;
        if((tolower(ch) == 'n'))
            main();
        else if ((tolower(ch) == 'y'))
            exit(0);
    }
    return 0;
}
