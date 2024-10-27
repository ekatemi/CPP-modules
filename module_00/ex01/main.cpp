#include "MyPhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <iomanip> 

int checkCmd(std::string cmd)
{
    if (cmd == "ADD" || cmd == "SEARCH" || cmd == "EXIT")
    {
        return (1);
    }  
    return (0);
}

void getInput(std::string &input, const std::string &prompt) {
    do {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (input.empty()) {
            std::cout << "Input cannot be empty. Please try again." << std::endl;;
        }
    } while (input.empty());
}

void fillData(std::string data[5]) {
    getInput(data[0], "Enter first name: ");
    getInput(data[1], "Enter last name: ");
    getInput(data[2], "Enter nickname: ");
    getInput(data[3], "Enter darkest secret: ");
    getInput(data[4], "Enter phone number: ");
}

std::string fitGrid(std::string str)
{
    if(str.length() > 10) {
       str = str.substr (0,8) + ".";
    }
    return str;
}

void showContacts(MyPhoneBook MyBook)
{
    // index, first name, last name and nickname.
    int i = 0;
    // Print headers with fixed width
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nick Name" << std::endl;
    std::cout << std::setfill('-') // fill character for the separator line
              << std::setw(43) << "" << std::setfill(' ') << std::endl;
    while (i < 8)
    {
        std::cout << std::setw(10) << i << "|"
        << std::setw(10) << fitGrid(MyBook.contacts[i].getFirstName()) << "|"
        << std::setw(10) << fitGrid(MyBook.contacts[i].getLastName()) << "|"
        << std::setw(10) << fitGrid(MyBook.contacts[i].getNickName()) << std::endl;
        i++;
    }
}

void printContactDetails(MyPhoneBook MyBook, int index)
{
    std::cout << "First name: " << MyBook.contacts[index].getFirstName() << std::endl;
    std::cout << "Last name: " << MyBook.contacts[index].getLastName() << std::endl;
    std::cout << "Nick name: " << MyBook.contacts[index].getNickName() << std::endl;
    std::cout << "Darkest Secret: " << MyBook.contacts[index].getDarkestSecret() << std::endl;
    std::cout << "Phone number: "<< MyBook.contacts[index].getPhoneNum() << std::endl;  
}

int main()
{
    MyPhoneBook MyBook;
    std::string cmd;
    std::string data[5];
    
    std::string index;

    std::cout << "     * My Awesome Phone Book *" << std::endl;
    std::cout << "ADD: save a new contact" << std::endl;
    std::cout << "SEARCH: display a specific contact" << std::endl;
    std::cout << "EXIT to quit the program" << std::endl;
    
    while (1)
    {
        std::cout << "Enter the command: ";
        std::getline(std::cin, cmd);
        if (cmd == "EXIT")
            break;
        else if (cmd == "ADD") {
            fillData(data);
            MyBook.addContact(data);
        }
        else if (cmd == "SEARCH") {
            showContacts(MyBook);
            while (42) { // Infinite loop
                std::cout << "Enter the index of contact (0-7): ";
                std::getline(std::cin, index);
                //std::cin >> index;

                // Check if the index is valid
                if (std::stoi(index) >= 0 && std::stoi(index) <= 7) {
                    break;
                }
                std::cout << "Invalid index." << std::endl;;
            }
            printContactDetails(MyBook, std::stoi(index));
        }
        else
            std::cout << "Wrong command, try again!\n";
    }
    return (0);
}