#include "contact.hpp"

Contact::Contact() {}

// Setters
void Contact::setFirstName(const std::string &value)     { _firstName     = value; }
void Contact::setLastName(const std::string &value)      { _lastName      = value; }
void Contact::setNickname(const std::string &value)      { _nickname      = value; }
void Contact::setPhoneNumber(const std::string &value)
{
    if (value.size() != 10)
        return ;
    for (size_t i = 0; i < value.size(); i++)
    {
        if (value[i] < '0' || value[i] > '9')
            return ;
    }
    _phoneNumber = value;
}
void Contact::setDarkestSecret(const std::string &value) { _darkestSecret = value; }

// Getters
std::string Contact::getFirstName()     const { return _firstName;     }
std::string Contact::getLastName()      const { return _lastName;      }
std::string Contact::getNickname()      const { return _nickname;      }
std::string Contact::getPhoneNumber()   const { return _phoneNumber;   }
std::string Contact::getDarkestSecret() const { return _darkestSecret; }