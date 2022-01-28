#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <fstream>
#include "filereader.h"
#include "distance_graph.h"


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
                 "                           3-get the cheapest trip                                                 \n"
                 "                           4-get the minimum distance between two places                           \n"
                 "                           5-exit                                                                  "<< std::endl;
    std::cout << std::string(4, '\n');
    std::cout << "                           Please enter your choice: ";
    std::cin >> option;
    if(option == 1){
        std::list<int>::iterator it;
        int index, destination_index;
        double latitude, longitude;
        std::string destination,stop;
        std::cout << '\n';
        std::cout << "                       Where are you at the moment? Put                                        \n"
                     "                       latitude in here! ";
        std::cin >> latitude;
        std::cout << '\n',
        std::cout << "                       And put longitude in here! ";
        std::cin  >> longitude;

        std::cout << "                       To what stop do you wish to go? Put                                     \n"
                     "                       its code in here! ";
        std::cin >> destination;
        std::cout << '\n';
        distance_graph graph= distance_graph(f1.number_of_stops(),true);
        graph.stops();
        graph.edges();
        index=graph.closeststop(latitude,longitude);
        destination_index=graph.get_index(destination);
        //for(it=graph.dijkstra_path(index,destination_index).begin(); it!= graph.dijkstra_path(index,destination_index).end();it++){
          //  stop=*it;
            //std::cout<< stop << "\n";
        //}
    }
    if(option == 2){
        double latitude, longitude;
        std::string destination;
        std::cout << '\n';
        std::cout << "                       Where are you at the moment? Put                                        \n"
                     "                       latitude in here! ";
        std::cin >> latitude;
        std::cout << '\n',
                std::cout << "                       And put longitude in here! ";
        std::cin  >> longitude;
        std::cout << "                       To what stop do you wish to go? Put                                     \n"
                     "                       its code in here! ";
        std::cin >> destination;
        std::cout << '\n';
        //f1.readstops();
        //main();
    }
    if(option == 3){
        double latitude, longitude;
        std::string destination;
        std::cout << '\n';
        std::cout << "                       Where are you at the moment? Put                                        \n"
                     "                       latitude in here! ";
        std::cin >> latitude;
        std::cout << '\n',
                std::cout << "                       And put longitude in here! ";
        std::cin  >> longitude;
        std::cout << "                       To what stop do you wish to go? Put                                     \n"
                     "                       its code in here! ";
        std::cin >> destination;
        std::cout << '\n';
        //f1.readstops();
        //main();
    }
    if(option == 4){
        distance_graph dg1(f1.number_of_stops(), true);
        std::map<std::string ,int> stops_map;
        std::string filename = "../dataset/stops.csv";
        std::ifstream stops{filename};
        f1.stops_code(stops, f1.number_of_stops(), stops_map);
        int integer_origin, integer_destination;
        std::string origin, destination;
        std::cout << "                       From which stop do you want to start?                                   \n"
                     "                       Put its code here: ";
        std::cin >> origin;
        std::cout << "                       To what stop do you wish to go? Put                                     \n"
                     "                       its code in here! ";
        std::cin >> destination;
        std::cout << '\n';
        integer_origin = stops_map[origin];
        integer_destination = stops_map[destination];
        dg1.dijkstra_distance(integer_origin, integer_destination);
        //f1.readstops();
        //main();
    }
    if(option == 5){
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
