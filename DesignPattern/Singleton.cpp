#include <iostream>
#include<string>
#include "./Singleton.h"

Singleton::Singleton() {
    std::cout << "�C���X�^���X�𐶐����܂����B" << std::endl;
}

Singleton* Singleton::getInstance() {
    static Singleton singleton;
    return &singleton;
}
