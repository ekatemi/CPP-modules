#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include "Contact.hpp"

class PhoneBook {
    private:
        Contact list[8]; //arr of 8 objects initialization inside PhoneBook object
        int curIdx;
    public:
        void setIdx(int num);
        //adds contact to list
        void addContact(std::string data[]); //["John Doe","Smith","Teddy","1233t","choko"]
        void getBook();
        void getContact(int n); 
};
#endif
