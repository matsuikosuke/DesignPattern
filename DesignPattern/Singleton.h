#ifndef SINGLETON_H_
#define SINGLETON_H_
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "array.h"

class Singleton{
private:
    //static Singleton singleton = new Singleton();
    Singleton();
public:
    static Singleton* getInstance();
};

#endif /* SINGLETON_H_ */