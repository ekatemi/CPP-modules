#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact {
  private:
    std::string FirstName;
    std::string LastName;
    std::string NickName;
    std::string DarkestSecret;
    std::string PhoneNum;
  public:
    // Default constructor
    Contact() {};
    //my constructor
    Contact(std::string data[5]);
      
    //getters const??? I need getters to access private data
    std::string getFirstName(void) const;
    std::string getLastName(void) const;
    std::string getNickName(void) const;
    std::string getDarkestSecret(void) const;
    std::string getPhoneNum(void) const;
};

#endif