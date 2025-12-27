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

    // ⭐ ADDED: helper validation function
    bool isValidISBN(int i) const;

public:
    Book();
    Book(string t, string a, int i, bool avail, string date);

    
    bool setBookDetails(string t, string a, int i, bool avail, string date);

    int getISBN() const;
    void display() const;
};

#endif
