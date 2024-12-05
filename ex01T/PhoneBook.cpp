#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

void PhoneBook::setIdx(int num)
{
    curIdx = num;
}


void PhoneBook::addContact()
{
    std::string data[5];
    fillData(data);
    // // Create a new Contact object using the input data
    Contact newContact(data);
    
    // // Add the new Contact to the list at the current index
    list[curIdx] = newContact;
    
    // // Increment the index, wrapping around to 0-7
    // //curIdx = (curIdx + 1) % 8;
    setIdx((curIdx + 1) % 8);
}

std::string fitCol(std::string output)
{
    
    if (output.length() >= 10)
        output = output.substr(0, 8) + '.'; //substr(idx init, longitud)
    return output;
}

void PhoneBook::searchContact()
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
