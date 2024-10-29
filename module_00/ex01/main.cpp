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

int getInput(std::string &input, const std::string &prompt) {
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        
        // Check for EOF
        if (std::cin.eof()) {
            std::cout << "\nEOF detected. Exiting program.\n";
            return 0; // Indicate failure
        }

        // Check if input is empty
        if (input.empty()) {
            std::cout << "Input cannot be empty. Please try again." << std::endl;
        } else {
            return 1; // Indicate success
        }
    }
    return 0;
}

void fillData(std::string data[5]) {
    if (!getInput(data[0], "Enter first name: ") ||
        !getInput(data[1], "Enter last name: ") ||
        !getInput(data[2], "Enter nickname: ") ||
        !getInput(data[3], "Enter darkest secret: ") ||
        !getInput(data[4], "Enter phone number: ")) {
        return; // Exit fillData if any getInput call fails
    }
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
        if (std::cin.eof()) {
            return 1; // Return to the calling function
        }
       
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
                if (std::cin.eof()) {
                        return 1; // Return to the calling function
                }      
                // Check if the index is valid
                if (std::isdigit(index[0]) && index[0] - '0' >= 0 && index[0] - '0' <= 8) {
                    break;
                }
                std::cout << "Invalid index." << std::endl;
            }
            MyBook.searchContact(index[0] - '0');
        }
        else
            std::cout << "Wrong command, try again!\n";
    }
    return (0);
}