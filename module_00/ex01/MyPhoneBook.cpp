#include "MyPhoneBook.hpp"
#include "Contact.hpp"

MyPhoneBook::MyPhoneBook() {
    index = 0;
};

void MyPhoneBook::addContact(std::string data[5])
{
    contacts[index] = Contact(data);
    index++;
    index = index % 8;
}