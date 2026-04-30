#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

bool isPerfectSquare(int n) {
    int root = sqrt(n);
    return (root * root == n);
}
bool isEven(int n) {
    return n % 2 == 0;
}

int main() {
    ifstream inFile("input.txt");
    ofstream outFile("output.txt");

    int num;

    if (!inFile) {
        cout << "Error opening input file!";
        return 1;
    }

    while (inFile >> num) {
        if (isPerfectSquare(num) && isEven(num)) {
            outFile << num << endl;
        }
    }

    inFile.close();
    outFile.close();

    cout << "Even perfect squares written to output.txt";
    return 0;
}