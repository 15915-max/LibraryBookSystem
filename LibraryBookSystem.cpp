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
    void setBookDetails(string t, string a, string i, bool avail, string date) {
        title = t;
        author = a;
        ISBN = i;
        availability = avail;
        dateAdd = date;
    }

    // --- Display book details ---
    void displayBookDetails() {
        cout << "\nTitle       : " << title;
        cout << "\nAuthor      : " << author;
        cout << "\nISBN        : " << ISBN;
        cout << "\nAvailable   : " << (availability ? "Yes" : "No");
        cout << "\nDate Added  : " << dateAdd;
    }

    // --- Getters ---
    string getISBN() { return ISBN; }
    bool isAvailable() { return availability; }

    // --- Borrow Book ---
    void borrowBook() {
        if (availability) {
            availability = false;
            cout << "Success: Book borrowed.\n";
        }
        else {
            cout << "Borrowed: Book is not available.\n";
        }
    }

    // --- Sort Books by ISBN (Bubble Sort) ---
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

int main() {
    Book library[5];

    // INITIALISE 5 BOOKS
    library[0].setBookDetails("Introduction of IT", "Lara Smith", "123", true, "2023-08-01");
    library[1].setBookDetails("C++ Programming", "Wayne Kevin", "856", true, "2021-02-21");
    library[2].setBookDetails("Algorithms", "Robert Sedgewick", "736", true, "2021-02-21");
    library[3].setBookDetails("Networking", "Henry Lee", "013", true, "2024-06-04");
    library[4].setBookDetails("Cyber Security", "Luis Jones", "633", true, "2024-02-05");

    // SORT BOOK DATA BY ISBN
    Book::sortBookData(library, 5);

    string searchISBN;

    while (true) {
        cout << "\nEnter ISBN to borrow (0 to quit): ";
        cin >> searchISBN;

        // --- ISBN == 0: DISPLAY ALL and exit (matches your diagram) ---
        if (searchISBN == "0") {
            cout << "\nDisplaying all book information:\n";
            for (int i = 0; i < 5; i++) {
                library[i].displayBookDetails();
            }
            cout << "\nProgram ended.\n";
            break;
        }

        bool found = false;

        // SEARCH FOR BOOK
        for (int i = 0; i < 5; i++) {
            if (library[i].getISBN() == searchISBN) {
                found = true;

                if (library[i].isAvailable()) {
                    library[i].borrowBook();  // SUCCESS
                }
                else {
                    cout << "Borrowed: Book is already borrowed.\n";
                }
                break;
            }
        }

        // IF NOT FOUND
        if (!found) {
            cout << "Not Found: No book with this ISBN.\n";
        }
    }

    return 0;
}
