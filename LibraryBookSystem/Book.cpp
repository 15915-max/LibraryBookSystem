#include "Book.h"
#include <iostream>
using namespace std;

Book::Book() {
    title = "";
    author = "";
    isbn = 0;
    availability = false;
    dateAdd = "";
}

Book::Book(string t, string a, int i, bool avail, string date) {
    title = t;
    author = a;
    isbn = i;
    availability = avail;
    dateAdd = date;
}

int Book::getISBN() const {
    return isbn;
}

void Book::display() const {
    cout << "Title: " << title
         << " | Author: " << author
         << " | ISBN: " << isbn << endl;
}
