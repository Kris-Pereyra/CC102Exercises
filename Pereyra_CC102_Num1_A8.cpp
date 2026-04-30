#include <iostream>
#include <fstream>
using namespace std;

void countLines() {
    ifstream file("STORY.TXT");
    string line;
    int count = 0;

    while (getline(file, line)) {
        if (line[0] != 'A') {
            count++;
        }
    }

    cout << "Lines not starting with A: " << count;
    file.close();
}

int main() {
    countLines();
}