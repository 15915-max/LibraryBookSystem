#ifndef BOOK_H   // Include guard
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
    // --- Set book details ---
    void setBookDetails(string t, string a, string i, bool avail, string date);

    // --- Display book details ---
    void displayBookDetails();

    // --- Getters ---
    string getISBN();
    bool isAvailable();

    // --- Borrow Book ---
    void borrowBook();

    // --- Sort Books by ISBN (Bubble Sort) ---
    static void sortBookData(Book arr[], int size);
};

#endif
