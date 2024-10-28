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
            MyBook.printContacts();
            while (42) { // Infinite loop
                std::cout << "Enter the index of contact (0-7): ";
                std::getline(std::cin, index);
                // Check if the index is valid
                if (std::stoi(index) >= 0 && std::stoi(index) <= 7) {
                    break;
                }
                std::cout << "Invalid index." << std::endl;
            }
            MyBook.searchContact(std::stoi(index));
        }
        else
            std::cout << "Wrong command, try again!\n";
    }
    return (0);
}