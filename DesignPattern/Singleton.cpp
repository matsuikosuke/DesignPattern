#include <iostream>
#include<string>
#include "./Singleton.h"

Singleton::Singleton() {
    std::cout << "インスタンスを生成しました。" << std::endl;
}

Singleton* Singleton::getInstance() {
    static Singleton singleton;
    return &singleton;
}
