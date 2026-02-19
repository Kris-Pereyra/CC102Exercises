#include <iostream>
using namespace std;

int main() {
    char rep;

    do {
        int students, quiz;

        cout << "Enter number of students: ";
        cin >> students;

        cout << "Enter number of quizzes: ";
        cin >> quiz;

        double scores[students][quiz];
        double average[students];

        for (int i = 0; i < students; i++) {
            double sum = 0;
            cout << "\nStudent " << i + 1 << " scores:\n";
                    for (int j = 0; j < quiz; j++) {
                        cin >> scores[i][j];
                        sum += scores[i][j];
            }
            average[i] = sum / quiz;
        }


        cout << "\nStudent\t\t";
        for (int j = 0; j < quiz; j++) {
            cout << "Q" << j + 1 << "\t\t";
        }
        cout << "Average\n";
         cout << "-----------------------------------------------------------------------\n";

        for (int i = 0; i < students; i++) {
            cout << i + 1 << "\t\t";
            for (int j = 0; j < quiz; j++) {
                cout << scores[i][j] << "\t\t";
            }
            cout << average[i] << endl;
        }


        cout << "\nRepeat? (y/n): ";
        cin >> rep;

    } while (rep == 'y' || rep == 'Y');

    return 0;
}
