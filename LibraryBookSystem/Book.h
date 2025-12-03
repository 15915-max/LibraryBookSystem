#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
using namespace std;

// =====================
//     Parent Class
// =====================
class Book {
protected:
    string title;
    string author;
    string ISBN;
    bool availability = true;
    string dateAdd;

public:
    Book() {}

    virtual ~Book() {} // IMPORTANT for polymorphism

    void setBookDetails(string t, string a, string i, bool avail, string date) {
        title = t;
        author = a;
        ISBN = i;
        availability = avail;
        dateAdd = date;
    }

    virtual void displayDetails() {
        cout << "\n----- BOOK DETAILS -----";
        cout << "\nTitle        : " << title;
        cout << "\nAuthor       : " << author;
        cout << "\nISBN         : " << ISBN;
        cout << "\nAvailable    : " << (availability ? "Yes" : "No");
        cout << "\nDate Added   : " << dateAdd;
    }

    void borrowBook() {
        if (availability) {
            availability = false;
            cout << "Success: Book borrowed.\n";
        }
        else {
            cout << "Borrowed: Book is not available.\n";
        }
    }

    string getISBN() { return ISBN; }

    static void sortBookData(Book* arr[], int size) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j]->getISBN() > arr[j + 1]->getISBN()) {
                    Book* temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
};

// =====================
//     Child Class 1
// =====================
class EBook : public Book {
private:
    string licenseEndDate;

public:
    void setLicense(string d) { licenseEndDate = d; }

    void displayDetails() override {
        Book::displayDetails();
        cout << "\nLicense End  : " << licenseEndDate;
    }
};

// =====================
//     Child Class 2
// =====================
class HardcopyBook : public Book {
private:
    string shelfNumber;

public:
    void setShelf(string s) { shelfNumber = s; }

    void displayDetails() override {
        Book::displayDetails();
        cout << "\nShelf Number : " << shelfNumber;
    }
};

#endif
