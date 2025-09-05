/* 
 unit8_file_handling.cpp
 Demonstrates file input/output (text), checking errors, sequential read/write,
 and simple random-access using seekg/seekp.
 Compile: g++ -std=c++17 -Wall unit8_file_handling.cpp -o unit8_file_handling
 Run: ./unit8_file_handling
*/

#include <iostream>
#include <fstream>
#include <string>

int main() {
    const char* filename = "example.txt";

    // Writing to file (sequential)
    {
        std::ofstream ofs(filename, std::ios::out);
        if (!ofs) {
            std::cerr << "Error opening file for write\n";
            return 1;
        }
        ofs << "Line 1: Hello file\n";
        ofs << "Line 2: 12345\n";
        ofs.close();
    }

    // Reading file (sequential)
    {
        std::ifstream ifs(filename, std::ios::in);
        if (!ifs) {
            std::cerr << "Error opening file for read\n";
            return 1;
        }
        std::string line;
        std::cout << "Reading file sequentially:\n";
        while (std::getline(ifs, line)) {
            std::cout << line << '\n';
        }
        ifs.close();
    }

    // Random access example: overwrite from certain position
    {
        std::fstream fs(filename, std::ios::in | std::ios::out);
        if (!fs) {
            std::cerr << "Error opening file for read/write\n";
            return 1;
        }
        fs.seekp(8); // move write pointer after "Line 1: "
        fs << "WORLD"; // overwrite part of file
        fs.close();
    }

    // Show final content
    {
        std::ifstream ifs(filename);
        std::cout << "Final file content:\n";
        std::string line;
        while (std::getline(ifs, line)) std::cout << line << '\n';
    }

    return 0;
}