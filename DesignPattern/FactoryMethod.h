#ifndef FACTORYMETHOD_H_
#define FACTORYMETHOD_H_
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "array.h"

class Product {
public:
    virtual void use() = 0;
};


class Factory {
public:
    Product* create(std::string owner) {
        Product* p = createProduct(owner);
        registerProduct(p);
        return p;
    }
protected:
    virtual Product*  createProduct(std::string owner) = 0;
    virtual void registerProduct(Product* p) = 0;
};

class IDCard : virtual public Product {
private:
    std::string owner;
public:
    IDCard(std::string owner);
    void use();
    std::string getOwner();
};

class IDCardFactory : virtual public Factory {
private:
    std::vector<std::string> owners;
protected:
    Product*  createProduct(std::string owner);
    void registerProduct(Product* p);
public:
    std::vector<std::string> getOwners();
};


#endif /* FACTORYMETHOD_H_ */