#ifndef TEMPLATE_H_
#define TEMPLATE_H_
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "array.h"

class AbstractDisplay {
public:
    virtual void open() = 0;
    virtual void print() = 0;
    virtual void close() = 0;
    void display();
};

class CharDisplay : public AbstractDisplay {
public:
    CharDisplay(std::string string);
    void open();
    void print();
    void close();
private:
    std::string string;
};

class StringDisplay : public AbstractDisplay {
public:
    StringDisplay(std::string string);
    void open();
    void print();
    void close();
    void printLine();
private:
    std::string string;
    int width;
};

#endif /* TEMPLATE_H_ */