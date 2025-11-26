#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string ISBN;
    bool availability;
    string dateAdd;

public:
    // Set book details
    void setBookDetails(string t, string a, string i, bool avail, string date) {
        title = t;
        author = a;
        ISBN = i;
        availability = avail;
        dateAdd = date;
    }

    // Display book details
    void displayBookDetails() {
        cout << "\nTitle       : " << title;
        cout << "\nAuthor      : " << author;
        cout << "\nISBN        : " << ISBN;
        cout << "\nAvailable   : " << (availability ? "Yes" : "No");
        cout << "\nDate Added  : " << dateAdd;
    }

    // Getters
    string getISBN() { return ISBN; }
    bool isAvailable() { return availability; }

    // Borrow book
    void borrowBook() {
        if (availability) {
            availability = false;
            cout << "Success: Book borrowed.\n";
        }
        else {
            cout << "Borrowed: Book is not available.\n";
        }
    }

    // Sort books by ISBN (Bubble Sort)
    static void sortBookData(Book arr[], int size) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j].ISBN > arr[j + 1].ISBN) {
                    Book temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
};

#endif


#pragma once
