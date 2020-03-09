#include <iostream>
#include "./Aggregate.h"


Iterator* BookShelf::iterator() {
    return new BookShelfIterator(*this);
}


BookShelfIterator::BookShelfIterator(BookShelf bookShelf) {
    this->bookShelf = bookShelf;
    this->index = 0;
}


void BookShelf::resize() {
    array<Book> new_books(std::max(2 * last, 1));
    for (int i = 0; i < last; i++) {
        new_books[i] = books[i];
    }
    books = new_books;
}