// Book.h
#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    int isbn;

public:
    Book(string t, string a, int i);
    int getISBN() const;
};

#endif
