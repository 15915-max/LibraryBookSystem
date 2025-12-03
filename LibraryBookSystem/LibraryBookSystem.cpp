#include <iostream>
#include "Book.h"
using namespace std;

// =====================
// Quick Sort Functions
// =====================
int partition(Book arr[], int low, int high) {
    string pivot = arr[high].getISBN();
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j].getISBN() <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(Book arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// =====================
// Main Function
// =====================
int main() {
    // =============================
    // A: Ascending Order Input
    // =============================
    Book asc[3];
    asc[0].setBookDetails("Introduction of IT", "Lara Smith", "123", true, "2023-08-01");
    asc[1].setBookDetails("C++ Programming", "Wayne Kevin", "856", true, "2021-02-21");
    asc[2].setBookDetails("Algorithms", "Robert Sedgewick", "736", true, "2021-02-21");

    cout << "\n===== ASCENDING ORDER BEFORE QUICK SORT =====\n";
    for (int i = 0; i < 3; i++) {
        asc[i].displayDetails();
        cout << "\n";
    }

    quickSort(asc, 0, 2);

    cout << "\n===== ASCENDING ORDER AFTER QUICK SORT =====\n";
    for (int i = 0; i < 3; i++) {
        asc[i].displayDetails();
        cout << "\n";
    }

    // =============================
    // B: Descending Order Input
    // =============================
    Book desc[3];
    desc[0].setBookDetails("Algorithms", "Robert Sedgewick", "736", true, "2021-02-21");
    desc[1].setBookDetails("C++ Programming", "Wayne Kevin", "856", true, "2021-02-21");
    desc[2].setBookDetails("Introduction of IT", "Lara Smith", "123", true, "2023-08-01");

    cout << "\n===== DESCENDING ORDER BEFORE QUICK SORT =====\n";
    for (int i = 0; i < 3; i++) {
        desc[i].displayDetails();
        cout << "\n";
    }

    quickSort(desc, 0, 2);

    cout << "\n===== DESCENDING ORDER AFTER QUICK SORT =====\n";
    for (int i = 0; i < 3; i++) {
        desc[i].displayDetails();
        cout << "\n";
    }

    // =============================
    // C: Mixed Order Input
    // =============================
    Book mix[3];
    mix[0].setBookDetails("C++ Programming", "Wayne Kevin", "856", true, "2021-02-21");
    mix[1].setBookDetails("Algorithms", "Robert Sedgewick", "736", true, "2021-02-21");
    mix[2].setBookDetails("Introduction of IT", "Lara Smith", "123", true, "2023-08-01");

    cout << "\n===== MIXED ORDER BEFORE QUICK SORT =====\n";
    for (int i = 0; i < 3; i++) {
        mix[i].displayDetails();
        cout << "\n";
    }

    quickSort(mix, 0, 2);

    cout << "\n===== MIXED ORDER AFTER QUICK SORT =====\n";
    for (int i = 0; i < 3; i++) {
        mix[i].displayDetails();
        cout << "\n";
    }

    return 0;
}
