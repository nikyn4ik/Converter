// Converter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

void File(const std::string& sourceFile, const std::string& destinationFile) {
    std::ifstream source(sourceFile);
    std::ofstream destination(destinationFile);
    std::string line;

    while (std::getline(source, line)) {
        destination << line << '\n';
    }
}

int main() {
    setlocale(LC_ALL, "");
    std::string path;
    std::string font;
    int size;
    int choice;

    while (true) {
        std::cout << "Menu:\n";
        std::cout << "1) File/Folder\n";
        std::cout << "2) Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch (choice) {
        case 1:
            std::cout << "Specify the path to the file or directory: ";
            std::getline(std::cin, path);

            if (std::ifstream(path)) {
                const std::string newFilePath = path.substr(0, path.find_last_of('.')) + "_copy.txt";
                CopyAndModifyFile(path, newFilePath);
                std::cout << "A new file has been created: " << newFilePath << '\n';
            }
            else {
                std::cout << "The specified file/directory does not exist.\n";
            }
            break;

        case 2:
            return 0;

        default:
            std::cout << " Invalid input.\n";
            break;
        }

        std::cout << '\n';
    }
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file