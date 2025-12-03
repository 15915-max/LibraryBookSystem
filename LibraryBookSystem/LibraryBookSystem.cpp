#include "Book.h" /* Add Book class skeleton with attributes and setBookDetails*/

int main() {
    Book library[5];

    library[0].setBookDetails("Introduction of IT", "Lara Smith", "123", true, "2023-08-01");
    library[1].setBookDetails("C++ Programming", "Wayne Kevin", "856", true, "2021-02-21");
    library[2].setBookDetails("Algorithms", "Robert Sedgewick", "736", true, "2021-02-21");
    library[3].setBookDetails("Networking", "Henry Lee", "013", true, "2024-06-04");
    library[4].setBookDetails("Cyber Security", "Luis Jones", "633", true, "2024-02-05");

    Book::sortBookData(library, 5);

    string searchISBN;
    while (true) {
        cout << "\nEnter ISBN to borrow (0 to quit): ";
        cin >> searchISBN;

        if (searchISBN == "0") {
            for (int i = 0; i < 5; i++) library[i].displayBookDetails();
            break;
        }

        bool found = false;
        for (int i = 0; i < 5; i++) {
            if (library[i].getISBN() == searchISBN) {
                found = true;
                library[i].borrowBook();
                break;
            }
        }

        if (!found) cout << "Not Found: No book with this ISBN.\n";
    }

    return 0;
}


