#include <iostream>
#include "Book.h"
using namespace std;

int main() {

    // Use POINTER array to enable polymorphism
    Book* library[5];

    // Create objects (mix of Parent, EBook, Hardcopy)
    library[0] = new Book();
    library[1] = new EBook();
    library[2] = new HardcopyBook();
    library[3] = new EBook();
    library[4] = new HardcopyBook();

    // Set book details
    library[0]->setBookDetails("Introduction of IT", "Lara Smith", "123", true, "2023-08-01");

    library[1]->setBookDetails("C++ Programming", "Wayne Kevin", "856", true, "2021-02-21");
    ((EBook*)library[1])->setLicense("2025-12-31");

    library[2]->setBookDetails("Algorithms", "Robert Sedgewick", "736", true, "2021-02-21");
    ((HardcopyBook*)library[2])->setShelf("A-12");

    library[3]->setBookDetails("Networking", "Henry Lee", "013", true, "2024-06-04");
    ((EBook*)library[3])->setLicense("2026-01-01");

    library[4]->setBookDetails("Cyber Security", "Luis Jones", "633", true, "2024-02-05");
    ((HardcopyBook*)library[4])->setShelf("B-03");

    // Sort all books by ISBN
    Book::sortBookData(library, 5);

    string searchISBN;
    while (true) {
        cout << "\nEnter ISBN to borrow (0 to quit): ";
        cin >> searchISBN;

        if (searchISBN == "0") {
            cout << "\n---- FINAL BOOK LIST ----\n";
            for (int i = 0; i < 5; i++) {
                library[i]->displayDetails();
                cout << "\n";
            }
            break;
        }

        bool found = false;
        for (int i = 0; i < 5; i++) {
            if (library[i]->getISBN() == searchISBN) {
                found = true;
                library[i]->borrowBook();
                break;
            }
        }

        if (!found) {
            cout << "Not Found: No book with this ISBN.\n";
        }
    }

    // Clean up memory
    for (int i = 0; i < 5; i++) {
        delete library[i];
    }

    return 0;
}
