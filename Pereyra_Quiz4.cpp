#include <iostream>
using namespace std;

const int rows = 5;
const int cols = 10;

int parking[rows][cols] = {0};
double total = 0;

bool isFull() {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(parking[i][j] == 0)
                return false;
        }
    }
    return true;
}

void viewParking() {
    cout << "\n   ";
    for(int i = 1; i <= cols; i++)
        cout << i << " ";
    cout << endl;

    char letter = 'A';

    for(int i = 0; i < rows; i++) {
        cout << letter++ << "  ";
        for(int j = 0; j < cols; j++) {
            cout << parking[i][j] << " ";
        }
        cout << endl;
    }
}

void parkCar() {

    if(isFull()) {
        cout << "Parking area is fully booked! No available slot.\n";
        return;
    }

    int r, c;

    cout << "Enter row number (1-5): ";
    cin >> r;

    cout << "Enter column number (1-10): ";
    cin >> c;

    if(r < 1 || r > 5 || c < 1 || c > 10) {
        cout << "Invalid slot selection!\n";
        return;
    }

    if(parking[r-1][c-1] == 1) {
        cout << "Slot already occupied!\n";
        return;
    }

    parking[r-1][c-1] = 1;

    cout << "Car successfully parked at "
         << char('A' + r - 1) << c << "!\n";
}

void leaveParking() {

    int r, c;

    cout << "Enter row number (1-5): ";
    cin >> r;

    cout << "Enter column number (1-10): ";
    cin >> c;

    if(r < 1 || r > 5 || c < 1 || c > 10) {
        cout << "Invalid slot selection!\n";
        return;
    }

    if(parking[r-1][c-1] == 0) {
        cout << "Slot is already empty!\n";
        return;
    }

    parking[r-1][c-1] = 0;

    total += 12;

    cout << "Car at " << char('A' + r - 1) << c
         << " has left the parking area.\n";

    cout << "Parking fee collected: P12.00\n";
    cout << "Updated Total Collection: P" << total << endl;
}

void resetParking() {

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            parking[i][j] = 0;
        }
    }

    cout << "Parking area reset successfully!\n";
}

int main() {

    int choice;

    do {

        cout << "\n===== CAR PARKING SYSTEM =====\n";
        cout << "Total Collection: P" << total << endl;

        cout << "1. View Parking Layout\n";
        cout << "2. Park a Car\n";
        cout << "3. Leave Parking\n";
        cout << "4. Reset Parking Area\n";
        cout << "5. Exit\n";
        cout << "==============================\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
                viewParking();
                break;

            case 2:
                parkCar();
                break;

            case 3:
                leaveParking();
                break;

            case 4:
                resetParking();
                break;

            case 5:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while(choice != 5);

    return 0;
}