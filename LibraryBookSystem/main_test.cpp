#include <iostream>
#include "Book_test.h"

using namespace std;

// Simple Quick Sort inside main.cpp
void quickSort(Book arr[], int low, int high) {
    if (low >= high) return;

    int pivot = arr[high].getISBN();
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j].getISBN() < pivot) {
            i++;
            Book temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    Book temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    quickSort(arr, low, i);
    quickSort(arr, i + 2, high);
}

int main() {

    // Correct book information
    Book b1("Introduction of IT", "Lara Smith", 123, true, "2023-08-01");
    Book b2("C++ Programming", "Wayne Kevin", 856, false, "2021-02-21");
    Book b3("Algorithms", "Robert Sedgewick", 736, true, "2021-02-21");

    // Incorrect book information (test cases)
    Book w1("12345", "?", -1, true, "2033-01-01");
    Book w2("", "", 0, false, "2022-13-01");
    Book w3("@@@", "", 999999, false, "Monday");

    // Arrays with different initial orders
    Book ascending[3]  = { b1, b3, b2 };
    Book descending[3] = { b2, b3, b1 };
    Book mixed[3]      = { b3, b1, b2 };

    // Apply Quick Sort
    quickSort(ascending, 0, 2);
    quickSort(descending, 0, 2);
    quickSort(mixed, 0, 2);

    // Display results
    cout << "Ascending Order Result:" << endl;
    for (int i = 0; i < 3; i++) ascending[i].display();

    cout << "\nDescending Order Result:" << endl;
    for (int i = 0; i < 3; i++) descending[i].display();

    cout << "\nMixed Order Result:" << endl;
    for (int i = 0; i < 3; i++) mixed[i].display();

    return 0;
}
