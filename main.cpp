#include <iostream>
#include <stdlib.h>
#include <unistd.h>


int main() {
    int option;
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
                 "                           1-display every available bus                                           \n"
                 "                           2-get the minimum distance between two places                           \n"
                 "                           3-something else                                                        \n"
                 "                           4-exit                                                                  "<< std::endl;
    std::cout << std::string(4, '\n');
    std::cout << "                           Please enter your choice: ";
    std::cin >> option;
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
