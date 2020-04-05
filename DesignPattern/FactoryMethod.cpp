#include <iostream>
#include<string>
#include "./FactoryMethod.h"


IDCard::IDCard(std::string owner) {
    std::cout << owner << "�̃J�[�h���쐬���܂��B" << std::endl;
    this->owner = owner;
}

void IDCard::use() {
    std::cout << owner << "�̃J�[�h���g�p���܂��B" << std::endl;
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