#ifndef ADAPTER_H_
#define ADAPTER_H_
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "array.h"

//Base class
class Banner {
private:
    std::string string;
public:
    Banner(std::string string);
    void showWithParen();
    void showWitAster();
    virtual ~Banner() {};
};


//Interface class(Superclass)
class Print {
public:
    virtual void printWeak() = 0;
    virtual void printStrong() = 0;
    virtual ~Print() {};
};


//Adapter
class PrintBanner : public Banner, public Print
{
public:
    PrintBanner(std::string string) : Banner(string) {}
    void printWeak();
    void printStrong();
    virtual ~PrintBanner() {};
};

//Deligation Adapter
class PrintBannerDeligation : public Print
{
private:
    Banner *banner;
public:
    PrintBannerDeligation(std::string string);
    void printWeak();
    void printStrong();
    virtual ~PrintBannerDeligation() {};
};


#endif /* ADAPTER_H_ */