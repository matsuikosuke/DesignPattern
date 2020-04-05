#include <iostream>
#include<string>
#include "./FactoryMethod.h"


IDCard::IDCard(std::string owner) {
    std::cout << owner << "のカードを作成します。" << std::endl;
    this->owner = owner;
}

void IDCard::use() {
    std::cout << owner << "のカードを使用します。" << std::endl;
}

std::string IDCard::getOwner() {
    return owner;
}



Product*  IDCardFactory::createProduct(std::string owner) {
    return new IDCard(owner);
}

void IDCardFactory::registerProduct(Product* p) {
    owners.push_back("test");
    //owners.push_back(p->getOwner());
}

std::vector<std::string> IDCardFactory::getOwners() {
    return owners;
}