#include <iostream>
#include <string>

std::string capitalize(const std::string& str) {
    if (str.empty()) {
        return str; // Return the empty string unchanged
    }
    
    std::string capitalizedStr = str; // Create a copy
    if (capitalizedStr[0] >= 'a' && capitalizedStr[0] <= 'z') {
        capitalizedStr[0] -= 32; // Convert the first character to uppercase
    }
    return capitalizedStr; // Return the modified string
}

int main() {
    std::string input;

    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    std::string capitalizedInput = capitalize(input);
    
    std::cout << "Capitalized: " << capitalizedInput << std::endl;

    return 0;
}
