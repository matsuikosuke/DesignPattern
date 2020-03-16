#include <iostream>
#include "./Aggregate.h"
#include "./Adapter.h"

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


    Print *pInheritance = new PrintBanner("Hello Inheritance");
    pInheritance->printWeak();
    pInheritance->printStrong();


    Print *pDeligation = new PrintBannerDeligation("Hello Deligation");
    pDeligation->printWeak();
    pDeligation->printStrong();

    return 0;
}