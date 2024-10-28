#ifndef MY_PHONE_BOOK_HPP
# define MY_PHONE_BOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>

class MyPhoneBook {
  public:
    Contact contacts[8];
    int index;
    MyPhoneBook();
    void addContact(std::string data[5]);
    void printContacts();
    void searchContact(int index);
};

#endif