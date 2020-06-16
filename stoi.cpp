#include <string>
#include <iostream>

int main(){
    std::string title = "2017, What a waste";
    std::string hex = "0xFFFFF1A";
    std::string hex_auto = "40c1";
    std::string bin = "-101010";

    std::string::size_type sz;

    int value_title = std::stoi(title, &sz);
    int value_hex = std::stoi(hex, nullptr, 16);
    int value_auto = std::stoi(hex_auto, nullptr, 0);
    int value_bin = std::stoi(bin, nullptr, 2);

    std::cout << "Title: " << value_title << " Remaining string: " << title.substr(sz) << std::endl;
    std::cout << "Hexadecimal: " << value_hex << std::endl;
    std::cout << "Auto-Judge: " << value_auto << std::endl;
    std::cout << "Binary: " << value_bin << std::endl;

}