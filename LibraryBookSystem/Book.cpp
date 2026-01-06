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

// Check if ISBN is valid (positive and more than 2 digits)
bool Book::isValidISBN(int i) const {
    return (i > 99);
}

// Simple check for date format YYYY-MM-DD
bool Book::isValidDate(const string& date) const {
    if (date.size() != 10) return false;
    if (date[4] != '-' || date[7] != '-') return false;
    // Optional: could also check that all other characters are digits
    return true;
}

bool Book::setBookDetails(string t, string a, int i, bool avail, string date) {
    bool valid = true;

    // Validate ISBN
    if (!isValidISBN(i)) {
        cout << "Error: ISBN is invalid (must be positive and at least 3 digits)" << endl;
        valid = false;
    }

    // Validate author
    if (a.empty()) {
        cout << "Error: Author cannot be empty" << endl;
        valid = false;
    }

    // Validate date
    if (!isValidDate(date)) {
        cout << "Error: Date format is invalid (expected YYYY-MM-DD)" << endl;
        valid = false;
    }

    // Only set details if all are valid
    if (!valid) return false;

    title = t;
    author = a;
    isbn = i;
    availability = avail;
    dateAdd = date;

    return true;
}

int Book::getISBN() const {
    return isbn;
}

void Book::display() const {
    cout << "Title: " << title
         << " | Author: " << author
         << " | ISBN: " << isbn
         << " | Available: " << (availability ? "Yes" : "No")
         << " | Date Added: " << dateAdd << endl;
}
