#include <iostream>
#include "phonebook.hpp"

int main() 
{
    PhoneBook   pb;
    std::string cmd;

    while (true) 
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        //std::getline(std::cin, cmd);

        if (!std::getline(std::cin, cmd))
        {
            std::cout << std::endl;
            exit(0);
        }
        
        //if (cmd == "")
        //{
        //    std::cout << std::endl;
        //    exit(0);
        //}
        if (cmd == "ADD")
            pb.addContact();
        else if (cmd == "SEARCH")
            pb.searchContact();
        else if (cmd == "EXIT")
            break;
    }
    return 0;
}