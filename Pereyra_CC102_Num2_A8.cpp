#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("TEXT.TXT");
    char ch;
    int upper = 0, lower = 0;

    while (file.get(ch)) {
        if (isupper(ch)) upper++;
        else if (islower(ch)) lower++;
    }

    cout << "Uppercase: " << upper << endl;
    cout << "Lowercase: " << lower << endl;

    file.close();
}