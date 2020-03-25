#include <iostream>
#include<string>
#include "./Template.h"


void AbstractDisplay::display() {
    open();
    for (int i = 0; i < 5; i++) {
        print();
    }
    close();
}

CharDisplay::CharDisplay(std::string string) {
    this->string = string;
}

void CharDisplay::open() {
    std::cout << "<<";
}

void CharDisplay::print() {
    std::cout << string;
}

void CharDisplay::close() {
    std::cout << ">>" << std::endl;

}



StringDisplay::StringDisplay(std::string string) {
    this->string = string;
    this->width = string.length();
}

void StringDisplay::open() {
    printLine();
}

void StringDisplay::print() {
    std::cout << "|" << string << "|" << std::endl;
}

void StringDisplay::close() {
    printLine();

}

void StringDisplay::printLine() {
    std::cout << "+";

    for (int i = 0; i < width; i++) {
        std::cout << "-";
    }

    std::cout << "+" << std::endl;
}
