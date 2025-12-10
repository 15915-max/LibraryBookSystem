#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    int isbn;
    bool availability;
    string dateAdd;

public:
    Book();
    Book(string t, string a, int i, bool avail, string date);

    int getISBN() const;
    void display() const;
};

#endif
