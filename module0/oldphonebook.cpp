#include "OldPhoneBook.hpp"

int main() {
    Phonebook phonebook;
    std::string command;

    while (true) {
        std::cout << "Commands: ADD, SEARCH, REMOVE, BOOKMARK, EXIT\n";
        std::cout << "Enter a command: ";
        std::cin >> command;

        if (command == "ADD") {
            phonebook.addContact();
        } else if (command == "SEARCH") {
            phonebook.searchContacts();
        } else if (command == "REMOVE") {
            phonebook.removeContact();
        } else if (command == "BOOKMARK") {
            phonebook.listBookmarkedContacts();
        } else if (command == "EXIT") {
            break;
        } else {
            std::cout << "Invalid command. Please try again.\n";
        }

        std::cout << std::endl;
    }

    return 0;
}