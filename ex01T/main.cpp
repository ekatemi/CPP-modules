#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

void getData(std::string &data, std::string prompt)
{
    while (std::cin && data.empty())
    {
        std::cout << prompt;
        if (!std::getline(std::cin, data)) 
        {
            std::cout << "Ctrl+D was pressed, exit the program";
            exit(0);
        }
    }
}

void fillData(std::string (&data)[5])
{
    getData(data[0], "Enter your First Name: ");
    getData(data[1], "Enter your Last Name: ");
    getData(data[2], "Enter your Nickname: ");
    getData(data[3], "Enter your phone num: ");
    getData(data[4], "Enter your Darkest Secret: ");
}

int main()
{
    std::string cmd;

    PhoneBook myBook;
    myBook.setIdx(0);
    
    while(true)
    {
        std::cout << "Enter a command ADD, SEARCH or EXIT: ";
        if (!std::getline(std::cin, cmd)) 
        {
            std::cout << "\nCtrl+D was pressed, exit the program";
            return (0);
        }
        if (cmd.length() == 4 && cmd == "EXIT")
            return (0);
        if (cmd.length() == 3 && cmd == "ADD")
            {
                myBook.addContact(); 
            }
        if (cmd.length() == 6 && cmd == "SEARCH")
            {
                myBook.searchContact();
            } 
    }     
    return (0);
}
