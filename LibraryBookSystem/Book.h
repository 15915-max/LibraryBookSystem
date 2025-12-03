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
   bool availability = true; // Initialise availability to true
   string dateAdd;

public:
   Book() : title(""), author(""), ISBN(""), availability(true), dateAdd("") {} // Initialise all members

   // Set book details
   void setBookDetails(string t, string a, string i, bool avail, string date) {
       title = t;
       author = a;
       ISBN = i;
       availability = avail;
       dateAdd = date;
   }

   // Virtual display
   virtual void displayDetails() {
       cout << "\n----- BOOK DETAILS -----";
       cout << "\nTitle        : " << title;
       cout << "\nAuthor       : " << author;
       cout << "\nISBN         : " << ISBN;
       cout << "\nAvailable    : " << (availability ? "Yes" : "No");
       cout << "\nDate Added   : " << dateAdd;
   }

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

   // Return book
   void returnBook() {
       availability = true;
       cout << "Success: Book returned.\n";
   }

   string getISBN() { return ISBN; }

   // Bubble Sort by ISBN
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
