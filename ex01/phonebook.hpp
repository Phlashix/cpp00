// PhoneBook.hpp
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contact.hpp"

class PhoneBook {
private:
    Contact _contacts[8];
    int     _count;
    int     _oldest;

public:
    PhoneBook();

    void addContact();
    void searchContact() const;

private:
    void    displayList() const;
    void    displayContact(int index) const;
    std::string truncate(const std::string &s) const;
};

#endif