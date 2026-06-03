#include "phonebook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : _count(0), _oldest(0) {}

std::string PhoneBook::truncate(const std::string &s) const {
    if (s.length() > 10)
        return s.substr(0, 9) + ".";
    return s;
}

static std::string promptField(const std::string &label) {
    std::string value;
    while (value.empty()) {
        std::cout << label << ": ";
        std::getline(std::cin, value);
    }
    return value;
}

void PhoneBook::addContact() {
    Contact newContact;

    newContact.setFirstName(promptField("First name"));
    newContact.setLastName(promptField("Last name"));
    newContact.setNickname(promptField("Nickname"));
    newContact.setPhoneNumber(promptField("Phone number"));
    newContact.setDarkestSecret(promptField("Darkest secret"));

    _contacts[_oldest] = newContact;
    _oldest = (_oldest + 1) % 8;
    if (_count < 8)
        _count++;
}

void PhoneBook::displayList() const {
    std::cout << std::setw(10) << "index"    << "|"
              << std::setw(10) << "first"    << "|"
              << std::setw(10) << "last"     << "|"
              << std::setw(10) << "nickname" << std::endl;
    for (int i = 0; i < _count; i++) {
        std::cout << std::setw(10) << std::right << i + 1                                    << "|"
                  << std::setw(10) << std::right << truncate(_contacts[i].getFirstName())    << "|"
                  << std::setw(10) << std::right << truncate(_contacts[i].getLastName())     << "|"
                  << std::setw(10) << std::right << truncate(_contacts[i].getNickname())     << std::endl;
    }
}

void PhoneBook::displayContact(int index) const {
    std::cout << "First name:     " << _contacts[index].getFirstName()     << std::endl;
    std::cout << "Last name:      " << _contacts[index].getLastName()      << std::endl;
    std::cout << "Nickname:       " << _contacts[index].getNickname()      << std::endl;
    std::cout << "Phone number:   " << _contacts[index].getPhoneNumber()   << std::endl;
    std::cout << "Darkest secret: " << _contacts[index].getDarkestSecret() << std::endl;
}

void PhoneBook::searchContact() const {
    if (_count == 0) {
        std::cout << "Phonebook is empty." << std::endl;
        return;
    }
    displayList();

    std::string input;
    std::cout << "Enter index: ";
    if (!std::getline(std::cin, input) || input.empty())
        return;

    int index = input[0] - '0';
    if (input.length() != 1 || index < 1 || index > _count) {
        std::cout << "Invalid index." << std::endl;
        return;
    }
    displayContact(index - 1);
}