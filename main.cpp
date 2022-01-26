#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include "filereader.h"


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
                 "                           1-display every line                                                    \n"
                 "                           2-display the stops of a certain line                                   \n"
                 "                           3-get the minimum distance between two places                           \n"
                 "                           4-exit                                                                  "<< std::endl;
    std::cout << std::string(4, '\n');
    std::cout << "                           Please enter your choice: ";
    std::cin >> option;
    if(option == 1){
        f1.readlinescsv("lines.csv");
        //main();
    }
    if(option == 2){
        int code, direction;
        std::cout << "What is the code of the line you want to see? ";
        std::cin >> code;
        std::cout << "What about its direction? Use 0 for the\n";
        std::cout << "original direction, or 1 for inverted direction ";
        std::cin >> direction;
        f1.readstops(code, direction);
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
