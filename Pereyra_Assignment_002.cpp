#include <iostream>
using namespace std;

void processGrades(int (*grades)[10], int students, int subjects) {
    int highest = grades[0][0];

    cout << "\nGrade Matrix:\n";
    for (int i = 0; i < students; i++) {
        for (int j = 0; j < subjects; j++) {
            cout << *(*(grades + i) + j) << "\t";

            if (*(*(grades + i) + j) > highest) {
                highest = *(*(grades + i) + j);
            }
        }
        cout << endl;
    }

    cout << "\nAverage Grade of Each Student:\n";
    for (int i = 0; i < students; i++) {
        float sum = 0;
        for (int j = 0; j < subjects; j++) {
            sum += *(*(grades + i) + j);
        }
        cout << "Student " << i + 1 << ": " << sum / subjects << endl;
    }

    cout << "\nHighest Grade: " << highest << endl;
}

int main() {
    int students, subjects;

    cout << "Enter number of students: ";
    cin >> students;

    cout << "Enter number of subjects: ";
    cin >> subjects;

    int grades[10][10];

    cout << "\nEnter grades:\n";
    for (int i = 0; i < students; i++) {
        for (int j = 0; j < subjects; j++) {
            cout << "Student " << i + 1 << ", Subject " << j + 1 << ": ";
            cin >> grades[i][j];
        }
    }

    processGrades(grades, students, subjects);

    return 0;
}