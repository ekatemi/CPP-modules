#include "MyPhoneBook.hpp"
#include "Contact.hpp"
#include <iomanip> 

MyPhoneBook::MyPhoneBook() {
    index = 0;
};

void MyPhoneBook::addContact(std::string data[5])
{
    contacts[index] = Contact(data);
    index++;
    index = index % 8;
}

std::string fitGrid(std::string str)
{
    if(str.length() > 10) {
       str = str.substr (0,8) + ".";
    }
    return str;
}

void MyPhoneBook::printContacts()
{
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
        << std::setw(10) << fitGrid(contacts[i].getFirstName()) << "|"
        << std::setw(10) << fitGrid(contacts[i].getLastName()) << "|"
        << std::setw(10) << fitGrid(contacts[i].getNickName()) << std::endl;
        i++;
    }
}

void MyPhoneBook::searchContact(int index)
{
    std::cout << "First name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nick name: " << contacts[index].getNickName() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
    std::cout << "Phone number: "<< contacts[index].getPhoneNum() << std::endl; 
}