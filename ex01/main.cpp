#include <iostream>
#include "phonebook.hpp"

int main(int ac, char **av) 
{
    PhoneBook   pb;
    std::string cmd;

    (void)av;
    if (ac != 1)
        exit(1);
    while (true) 
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";

        if (!std::getline(std::cin, cmd))
        {
            std::cout << std::endl;
            exit(0);
        }
        
        if (cmd == "ADD")
            pb.addContact();
        else if (cmd == "SEARCH")
            pb.searchContact();
        else if (cmd == "EXIT")
            break;
    }
    return 0;
}