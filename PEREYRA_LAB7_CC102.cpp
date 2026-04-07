#include <iostream>
#include <vector>
using namespace std;

struct book {
    string barcode;
    string title;
    int year;
    int rating;
};

string getCategory(int rating) {
    if (rating == 5) return "Excellent";
    else if (rating == 4) return "Very Good";
    else if (rating == 3) return "Good";
    else if (rating == 2) return "Fair";
    else if (rating == 1) return "Poor";
    else return "No Rating";
}

bool isUniqueBarcode(const vector<book>& books, string code) {
    for (int i = 0; i < books.size(); i++) {
        if (books[i].barcode == code)
            return false;
    }
    return true;
}

void display(const vector<book>& books) {
    cout << "\nBarcode\tTitle\tYear\tRating\tCategory\n";
    for (int i = 0; i < books.size(); i++) {
        cout << books[i].barcode << "\t"
             << books[i].title << "\t"
             << books[i].year << "\t"
             << books[i].rating << "\t"
             << getCategory(books[i].rating) << endl;
    }
}

int main() {
    vector<book> books;
    int choice;

    do {
        cout<< "===============";
        cout << "\n1. Add Book\n2. Edit Book\n3. Delete Book\n4. Display Books\n5. Exit";
        cout<< "\n===============";
        cout<< "\nEnter Choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            book b;

            do {
                cout << "Enter Barcode: ";
                getline(cin, b.barcode);
                if (!isUniqueBarcode(books, b.barcode))
                    cout << "Barcode exists! Try again.\n";
            } while (!isUniqueBarcode(books, b.barcode));

            cout << "Enter Title: ";
            getline(cin, b.title);
            cout << "Enter Year: ";
            cin >> b.year;
            cout << "Enter Rating: ";
            cin >> b.rating;
            cin.ignore();

            books.push_back(b);
        }
        else if (choice == 2) {
            string code;
            cout << "Enter Barcode to edit: ";
            getline(cin, code);
            for (int i = 0; i < books.size(); i++) {
                if (books[i].barcode == code) {
                    cout << "New Title: ";
                    getline(cin, books[i].title);
                    cout << "New Year: ";
                    cin >> books[i].year;
                    cout << "New Rating: ";
                    cin >> books[i].rating;
                    cin.ignore();
                }
            }
        }
        else if (choice == 3) {
            string code;
            cout << "Enter Barcode to delete: ";
            getline(cin, code);
            for (int i = 0; i < books.size(); i++) {
                if (books[i].barcode == code) {
                    books.erase(books.begin() + i);
                    break;
                }
            }
        }
        else if (choice == 4) {
            display(books);
        }

    } while (choice != 5);

    return 0;
}
