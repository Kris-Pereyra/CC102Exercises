#include <iostream>
#include <fstream>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int countPrimesInFile(string filename) {
    ifstream file(filename);
    int num, count = 0;

    if (!file) {
        cout << "Error opening file!" << endl;
        return 0;
    }

    while (file >> num) {
        if (isPrime(num)) {
            count++;
        }
    }

    file.close();
    return count;
}

int main() {
    string filename = "NUMS.TXT";
    int result = countPrimesInFile(filename);

    cout << "Number of prime numbers: " << result << endl;

    return 0;
}