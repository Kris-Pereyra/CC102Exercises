#include <iostream>
using namespace std;

int main() {
    char rep;

    do {
        const int products = 5;
        const int salesPerson = 4;

        double sales[products][salesPerson] = {0};

        int sp, pr;
        double amount;
        char choice;

        do {
            cout << "Salesperson: ";
            cin >> sp;

            cout << "Product: ";
            cin >> pr;

            cout << "Amount: ";
            cin >> amount;

            sales[pr - 1][sp - 1] += amount;

            cout << endl;
            cout << "Add another entry? (y/n): ";
            cin >> choice;

        } while (choice == 'y' || choice == 'Y');

        cout << endl;

        cout << "\t\tSalesperson\n";
        cout << "Product\t1\t2\t3\t4\tTotal\n";

        double grandTotal = 0;

        for (int p = 0; p < products; p++) {
            double rowTotal = 0;

            cout << p + 1 << "\t";

            for (int s = 0; s < salesPerson; s++) {
                cout << sales[p][s] << "\t";
                rowTotal += sales[p][s];
            }

            cout << rowTotal << endl;
            grandTotal += rowTotal;
        }

        cout << "Total\t";

        for (int s = 0; s < salesPerson; s++) {
            double columnTotal = 0;

            for (int p = 0; p < products; p++) {
                columnTotal += sales[p][s];
            }

            cout << columnTotal << "\t";
        }

        cout << grandTotal << endl;

        cout << "\nRepeat? (y/n): ";
        cin >> rep;

    } while (rep == 'y' || rep == 'Y');

    return 0;
}
