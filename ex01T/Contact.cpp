#include "Contact.hpp"

//external constructor definition
Contact::Contact(std::string data[5])
{
    firstName = data[0];
    lastName = data[1];
    nickName = data[2];
    phoneNum = data[3];
    darkestSecret = data[4];
}
//const indicates it only reads and not modifies
    std::string Contact::getFirstName() const {
    return firstName;
    }
    std::string Contact::getLastName() const {
    return lastName;
    }       
    std::string Contact::getNickName() const{
    return nickName;
    }       
    std::string Contact::getDarkestSecret() const{
    return darkestSecret;
    }
    std::string Contact::getPhoneNum() const{
    return phoneNum;
    }
    

