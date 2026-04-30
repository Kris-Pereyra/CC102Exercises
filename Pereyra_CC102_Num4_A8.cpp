#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("TEXT.TXT");
    int freq[256] = {0};
    char ch;

    while (file.get(ch)) {
        freq[(int)ch]++;
    }

    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0)
            cout << (char)i << " : " << freq[i] << endl;
    }

    file.close();
    return 0;
}