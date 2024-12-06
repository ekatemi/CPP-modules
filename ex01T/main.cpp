#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

int checkGetLine(std::string &data)
{
    if (!std::getline(std::cin, data)) 
    {
        std::cout << "\nCtrl+D was pressed, exit the program";
        return (0);
    }
    return (1);
}

void getData(std::string &data, std::string prompt)
{
    while (std::cin && data.empty())
    {
        std::cout << prompt;
        if (!std::getline(std::cin, data)) 
        {
            std::cout << "\nCtrl+D was pressed, exit the program";
            exit(0);
        }
    }
}
//fills array data[5] from the input
void fillData(std::string (&data)[5])
{
    getData(data[0], "Enter your First Name: ");
    getData(data[1], "Enter your Last Name: ");
    getData(data[2], "Enter your Nickname: ");
    getData(data[3], "Enter your phone num: ");
    getData(data[4], "Enter your Darkest Secret: ");
}

void resetData(std::string (&data)[5])
{
    int i = 0;
    while (i < 5)
    {
        data[i].clear();
        i++;
    }
}

int main()
{
    PhoneBook myBook;
    myBook.setIdx(0);
    std::string cmd;
    std::string data[5];
    int n;

    while(true)//command loop, break only with EXIT or error getline
    {
        std::cout << "Enter a command ADD, SEARCH or EXIT: ";
        if (!checkGetLine(cmd)) 
            return (0);
        if (cmd.length() == 4 && cmd == "EXIT")
            return (0);
        if (cmd.length() == 3 && cmd == "ADD")
            {
                resetData(data);
                fillData(data);
                while(true)
                {
                    std::cout << "Save? Y/N: "; 
                    if(!checkGetLine(cmd))
                        return (1);
                    if (cmd.length() == 1 && cmd == "N")
                        break ;
                    else if (cmd.length() == 1 && cmd == "Y")
                    {
                        myBook.addContact(data);
                        break ;

                    }
                } 
            }
        if (cmd.length() == 6 && cmd == "SEARCH")
            {
                myBook.getBook();
                while(true)
                {
                    std::cout << "Enter a number from 0 to 7: ";
                    if (!checkGetLine(cmd)) 
                        return (1);
                    if (cmd.length() == 1 && (cmd[0] - '0') < 8)
                    {
                        n = cmd[0] - '0';
                        myBook.getContact(n);
                        break ;
                    }
                    else
                        std::cout << "Wrong number!\n";
                }
            }
    }     
    return (0);
}
