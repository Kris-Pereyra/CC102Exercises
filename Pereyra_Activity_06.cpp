#include <iostream>
using namespace std;

struct Book {
    int barcode;
    string title;
    int year;
    int rating;
    string category;
};

string category(int rating) {
    if(rating == 5) return "Excellent";
    else if(rating == 4) return "Very Good";
    else if(rating == 3) return "Good";
    else if(rating == 2) return "Fair";
    else if(rating == 1) return "Poor";
    else return "No Rating";
}


int input(Book b[]) {
    int number;
    
    cout<< "============================";
    cout << "\nEnter number of books: ";
    cin >> number;

    for(int i = 0; i < number; i++) {

        do {
            cout << "\nBarcode: ";
            cin >>  b[i].barcode;

            if(b[i-1].barcode == b[i].barcode) {
                cout << "Barcode already exists! Enter again.\n";
            }
        } while(b[i-1].barcode == b[i].barcode);

        cout << "Title: ";
        cin.ignore();
        getline (cin,b[i].title);
        

        cout << "Year: ";
        cin >> b[i].year;

        cout << "Rating (0-5): ";
        cin >> b[i].rating;
    }

    return number;
}


int display(Book b[], int number) {
    cout << "\n\n------------------------------------------\n";
    cout << "Barcode\tTitle\tYear\tRating\tCategory\n\n";

    for(int i = 0; i < number; i++) {
        cout << b[i].barcode << "\t"
             << b[i].title << "\t"
             << b[i].year << "\t"
             << b[i].rating << "\t"
             << category(b[i].rating) << endl;
    }
    cout<< "\n------------------------------------------";
    return 0;
}

int main() {
    char rep;

    do {
        Book obj[20]; 

        int number = input(obj);  
        display(obj, number);   

        cout << "\n\nDo you want to repeat? (Y/N): ";
        cin >> rep;
        cout<< "============================\n\n";

    } while(rep == 'Y' || rep == 'y');

    return 0;
}