#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

void PhoneBook::setIdx(int num)
{
    curIdx = num;
}

void PhoneBook::addContact(std::string data[])
{
    Contact newContact(data);
    list[curIdx] = newContact;
    setIdx((curIdx + 1) % 8);
}

std::string fitCol(std::string output)
{
    
    if (output.length() >= 10)
        output = output.substr(0, 8) + '.'; //substr(idx init, longitud)
    return output;
}

void PhoneBook::getBook() //just show book
{
    int i = 0;
    std::cout << std::right 
        << std::setw(10) << "Index" << '|' 
        << std::setw(10) << "First Name" << '|' 
        << std::setw(10) << "Last Name" << '|' 
        << std::setw(10) << "NickName" << std::endl;
    while (i < 8)
    {
        std::cout << std::right 
            << std::setw(10) << i << '|'
            << std::setw(10) << fitCol(list[i].getFirstName()) << '|'
            << std::setw(10) << fitCol(list[i].getLastName()) << '|'
            << std::setw(10) << fitCol(list[i].getNickName()) << std::endl;
        i++;
    }
}

void PhoneBook::getContact(int n) //shows contact with specific index
{
    if (list[n].getFirstName().length() > 0) //list not empty
    {
        std::cout << "Name: " << list[n].getFirstName() << std::endl;
        std::cout << "Last Name: " << list[n].getLastName() << std::endl;
        std::cout << "Nickname: " << list[n].getNickName() << std::endl;
        std::cout << "Phone: " << list[n].getPhoneNum() << std::endl;
        std::cout << "Darkest Secret: " << list[n].getDarkestSecret() << std::endl;  
    }
    else
        std::cout << "Empty" << std::endl;

}

