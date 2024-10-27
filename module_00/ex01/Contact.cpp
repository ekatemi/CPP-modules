#include "Contact.hpp"

Contact::Contact(std::string data[5]) {
        FirstName = data[0];
        LastName = data[1];
        NickName = data[2];
        DarkestSecret = data[3];
        PhoneNum = data[4];
      }
std::string Contact::getFirstName() const {
    return FirstName;
}
std::string Contact::getLastName() const {
    return LastName;
}       
std::string Contact::getNickName() const{
    return NickName;
}       
std::string Contact::getDarkestSecret() const{
    return DarkestSecret;
    }
std::string Contact::getPhoneNum() const{
    return PhoneNum;
}  