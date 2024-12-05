#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact {
    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNum;
        std::string darkestSecret;
    public:
        // Default constructor
        Contact() {};
        //my constructor
        Contact(std::string data[5]);

        
        std::string getFirstName(void) const;
        std::string getLastName(void) const;
        std::string getNickName(void) const;
        std::string getDarkestSecret(void) const;
        std::string getPhoneNum(void) const;
};

#endif
