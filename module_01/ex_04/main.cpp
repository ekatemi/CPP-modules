#include <iostream>
#include <string>
#include <fstream> //for reading and writing a file

void myReplace(std::string& line, const std::string& s1, const std::string& s2) {
    size_t pos = 0;
    if (s1.empty()) return; //without this pos is always 0 end inf loop
    while ((pos = line.find(s1, pos)) != std::string::npos)
    {
        line.erase(pos, s1.size()); // Remove `s1`
        line.insert(pos, s2); 
        pos += s2.length(); 
    }
}

int main(int argc, char** argv)
{
    if(argc != 4) {
        std::cout << "Arguments should be <filename> <s1> <s2>\n";
        return 1;
    }

    std::string fileName = argv[1];
    const std::string sub1 = argv[2];
    const std::string sub2 = argv[3];
   
    std::string outFile = fileName + ".replace" + ".txt";
    
    std::ifstream inputFile(fileName + ".txt"); // Open the source file for reading.
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file.\n"; //stram for error messages
        return 1;
    }
    std::ofstream outputFile(outFile); // Open the destination file for writing.

    if (!outputFile.is_open()) {
        std::cerr << "Error opening file(s).\n"; //stram for error messages
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        myReplace(line, sub1, sub2);
        outputFile << line << '\n'; // Copy each line to the destination file.
    }

    inputFile.close();
    outputFile.close();
    return 0;
}
