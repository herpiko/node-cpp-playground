#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void writeToTextFile(const std::string& text, const std::string& filePath) {
    std::ofstream file(filePath, std::ios::binary);
    if (file.is_open()) {
        file.write(reinterpret_cast<const char*>(text.data()), text.size());
        file.close();
        std::cout << "Binary data successfully written to file: " << filePath << std::endl;
    } else {
        std::cerr << "Error: Unable to open file for writing: " << filePath << std::endl;
    }
}

std::string readFromTextFile(const std::string& filePath) {
    std::ifstream file(filePath);
    std::string content;
    if (file.is_open()) {
        std::getline(file, content, '\0'); // Read entire file content
        file.close();
        std::cout << "Text successfully read from file: " << filePath << std::endl;
    } else {
        std::cerr << "Error: Unable to open file for reading: " << filePath << std::endl;
    }
    return content;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <action> <text> <file_path>" << std::endl;
        return 1;
    }

    std::string action = argv[1];
    std::string text = (argc > 3) ? argv[2] : ""; // Text is optional for read action
    std::string filePath = (argc > 3) ? argv[3] : argv[2]; // If text is not provided, treat second argument as filePath

    if (action == "write") {
        writeToTextFile(text, filePath);
    } else if (action == "read") {
        std::cout << readFromTextFile(filePath);
    } else {
        std::cerr << "Error: Invalid action. Valid actions are 'write' and 'read'." << std::endl;
        return 1;
    }

    return 0;
}

