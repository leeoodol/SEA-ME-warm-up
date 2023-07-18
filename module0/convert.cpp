#include <iostream>
#include <string>

std::string convertToUpper(const std::string& str) {
    std::string convertedStr = str;
    for (char& c : convertedStr) {
        if (std::isalpha(c)) {
            c = std::toupper(c);
        }
    }
    return convertedStr;
}

std::string convertToLower(const std::string& str) {
    std::string convertedStr = str;
    for (char& c : convertedStr) {
        if (std::isalpha(c)) {
            c = std::tolower(c);
        }
    }
    return convertedStr;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "Usage: ./convert {command} {string}\n";
        return 1;
    }

    std::string command = argv[1];
    std::string str = argv[2];
		if(argc != 3){
			for(int i=3; i<argc;i++){
				str += " ";
				str += argv[i];
			}
		}
    std::string result;

    if (command == "up") {
        result = convertToUpper(str);
    } else if (command == "down") {
        result = convertToLower(str);
    } else {
        std::cout << "Invalid command. Please use 'up' or 'down'.\n";
        return 1;
    }

    std::cout << result << "\n";
    return 0;
}