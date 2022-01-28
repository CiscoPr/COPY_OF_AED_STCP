#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include "filereader.h"
#include "distance_graph.h"


//! this will be the function with the menu
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
                 "                           2-display the stops of a certain line                                   \n"
                 "                           3-get the minimum distance between two places                           \n"
                 "                           4-exit                                                                  "<< std::endl;
    std::cout << std::string(4, '\n');
    std::cout << "                           Please enter your choice: ";
    std::cin >> option;
    if(option == 1){
        std::string origin, destination;
        std::cout << '\n';
        std::cout << "                       What will be your first stop? Put                                       \n"
                     "                       its name in here! ";
        std::cin >> origin;
        std::cout << '\n',
        std::cout << "                       To what stop do you wish to go? Put                                     \n"
                     "                       its name in here! ";
        std::cin >> destination;
        std::cout << '\n';

    }
    if(option == 2){
        //f1.readstops();
        //main();
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
