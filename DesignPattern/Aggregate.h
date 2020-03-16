#ifndef AGGREGATE_H_
#define AGGREGATE_H_
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "array.h"

//Forward declaration
//class Aggregate;
class Iterator;

//class
class Book {
private:
    std::string name;
public:
    //Default Constructor
    Book() {}

    //
    Book(std::string name) {
        this->name = name;
    }

    //
    std::string getName() {
        return name;
    }
};

//Interface class(Superclass)
class Aggregate {
public:
    //Create one Iterator corresponding to the aggregate
    virtual Iterator* iterator() = 0;

    //Destructor
    virtual ~Aggregate() {};
};

class Iterator
{
public:
    //Member function to check for the next element
    //true:exist, false:nothing
    virtual bool hasNext() = 0;

    //Member function to obtain the next element
    virtual Book next() = 0;

    //Destructor
    virtual ~Iterator() {}
};

//Subclass
class BookShelf : virtual public Aggregate {
private:
    array<Book> books;
    int last;
    void resize();
public:
    BookShelf() : books(1) {
        last = 0;
    }

    //
    BookShelf(int maxsize) : books(maxsize) {
        last = 0;
    }

    //
    Book getBookAt(int index) {
        return books[index];
    }

    void appendBook(Book book) {
        if (last >= books.length) {   //If no more can be added to the array
            resize();
        }
        books[last] = book;
        last++;
    }

    int getLength() {
        return last;
    }

    Iterator* iterator() override;
};

class BookShelfIterator : public Iterator {
private:
    BookShelf bookShelf;
    int index = 0;
public:
    BookShelfIterator(BookShelf bookShelf);

    bool hasNext() override {
        if (index < bookShelf.getLength()) {
            return true;
        }
        else {
            return false;
        }
    }

    Book next() override {
        Book book = bookShelf.getBookAt(index);
        index++;
        return book;
    }
};
#endif /* AGGREGATE_H_ */