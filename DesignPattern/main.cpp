#include <iostream>
#include "./Aggregate.h"
#include "./Adapter.h"
#include "./Template.h"
#include "./FactoryMethod.h"
#include "./Singleton.h"

int main() {
    //Chapter1:Iterator
    std::cout << "Chapter1:Iterator" << std::endl;

    BookShelf bookshelf(1);

    Book book1("BOOK TEST 1");
    bookshelf.appendBook(book1);

    Book book2("BOOK TEST 2");
    bookshelf.appendBook(book2);

    Book book3("BOOK TEST 3");
    bookshelf.appendBook(book3);

    Book book4("BOOK TEST 4");
    bookshelf.appendBook(book4);

    Book book5("BOOK TEST 5");
    bookshelf.appendBook(book5);

    //Create Iterator
    Iterator *it = bookshelf.iterator();

    while (it->hasNext()) {
        Book book = it->next();
        printf("%s\n", book.getName().c_str());
    }


    //Chapter2:Adapter
    std::cout << "Chapter2:Adapter" << std::endl;

    PrintBanner p("Hello");
    p.printWeak();
    p.printStrong();

    PrintBanner pp("Hello");
    Print& ppp = pp;
    ppp.printWeak();
    ppp.printStrong();

    Print *pInheritance = new PrintBanner("Hello Inheritance");
    pInheritance->printWeak();
    pInheritance->printStrong();


    Print *pDeligation = new PrintBannerDeligation("Hello Deligation");
    pDeligation->printWeak();
    pDeligation->printStrong();

    //Chapter3:Template
    CharDisplay *oneChar = new CharDisplay("H");
    oneChar->display();

    StringDisplay *oneString1 = new StringDisplay("Hello, World.");
    oneString1->display();

    StringDisplay *oneString2 = new StringDisplay("����ɂ���");
    oneString2->display();


    //Chapter4:Factory Method
    Factory* factory = new IDCardFactory();
    Product* card1 = factory->create("�c��");
    Product* card2 = factory->create("���");
    Product* card3 = factory->create("�ؑ�");
    card1->use();
    card2->use();
    card3->use();


    //Chapter5:Singleton
    Singleton* obj1 = Singleton::getInstance();
    Singleton* obj2 = Singleton::getInstance();

    if (obj1 == obj2) {
        std::cout << "obj1��obj2�����̓C���X�^���X�ł��B" << std::endl;
    }
    else {
        std::cout << "obj1��obj2�����̓C���X�^���X�ł͂���܂���B" << std::endl;
    }



    return 0;
}