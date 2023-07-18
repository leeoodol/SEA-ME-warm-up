#include <iostream>
#include <vector>

class Contact {
private:
    std::string name;
    std::string phoneNumber;
    std::string nickname;
    bool bookmarked;

public:
    Contact(const std::string& name, const std::string& phoneNumber, const std::string& nickname)
        : name(name), phoneNumber(phoneNumber), nickname(nickname), bookmarked(false) {}

    std::string getName() const {
        return name;
    }

    std::string getPhoneNumber() const {
        return phoneNumber;
    }

    std::string getNickname() const {
        return nickname;
    }

    bool isBookmarked() const {
        return bookmarked;
    }

    void toggleBookmark() {
        bookmarked = !bookmarked;
    }
};

class Phonebook {
private:
    std::vector<Contact> contacts;

public:
    void addContact() {
        std::string name, phoneNumber, nickname;
        std::cout << "Enter name: ";
        std::cin >> name;
        std::cout << "Enter phone number: ";
        std::cin >> phoneNumber;
        std::cout << "Enter nickname: ";
        std::cin >> nickname;

        Contact contact(name, phoneNumber, nickname);
        contacts.push_back(contact);
        std::cout << "Contact added successfully.\n";
    }

    void searchContacts() {
        if (contacts.empty()) {
            std::cout << "No contacts available.\n";
            return;
        }

        std::cout << "Contacts:\n";
        for (size_t i = 0; i < contacts.size(); ++i) {
            std::cout << i << ": " << contacts[i].getName() << std::endl;
        }

        std::cout << "Enter the index of the contact to display details (or -1 to cancel): ";
        int index;
        std::cin >> index;

        if (index >= 0 && static_cast<size_t>(index) < contacts.size()) {
            std::cout << "Name: " << contacts[index].getName() << std::endl;
            std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
            std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;

            std::cout << "Do you want to bookmark this contact? (Y/N): ";
            char choice;
            std::cin >> choice;

            if (choice == 'Y' || choice == 'y') {
                contacts[index].toggleBookmark();
                std::cout << "Contact bookmarked.\n";
            }
        } else {
            std::cout << "Invalid index. Canceling operation.\n";
        }
    }

    void removeContact() {
        if (contacts.empty()) {
            std::cout << "No contacts available.\n";
            return;
        }

        std::cout << "Enter the index of the contact to remove: ";
        int index;
        std::cin >> index;

        if (index >= 0 && static_cast<size_t>(index) < contacts.size()) {
            contacts.erase(contacts.begin() + index);
            std::cout << "Contact removed successfully.\n";
        } else {
            std::cout << "Invalid index. Canceling operation.\n";
        }
    }

    void listBookmarkedContacts() {
        bool foundBookmarkedContact = false;

        std::cout << "Bookmarked Contacts:\n";
        for (const auto& contact : contacts) {
            if (contact.isBookmarked()) {
                std::cout << "Name: " << contact.getName() << std::endl;
                std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
                std::cout << "Nickname: " << contact.getNickname() << std::endl;
                std::cout << "---------------\n";
                foundBookmarkedContact = true;
            }
        }

        if (!foundBookmarkedContact) {
            std::cout << "No bookmarked contacts available.\n";
        }
    }
};