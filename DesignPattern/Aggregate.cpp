#include <iostream>
#include "./Aggregate.h"


Iterator* BookShelf::iterator() {
    return new BookShelfIterator(*this);
}


BookShelfIterator::BookShelfIterator(BookShelf bookShelf) {
    this->bookShelf = bookShelf;
    this->index = 0;
}