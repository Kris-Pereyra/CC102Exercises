#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ofstream outFile("original.txt");
    if (!outFile.is_open()) {
        cout << "Error creating original.txt" << endl;
        return 1;
    }

    outFile << "One" << endl;
    outFile << "Two" << endl;
    outFile << "Three" << endl;
    outFile << "Four" << endl;
    outFile << "Five" << endl;
    outFile << "Six" << endl;
    outFile.close();

    ifstream inFile("original.txt");
    if (!inFile.is_open()) {
        cout << "Error opening original.txt" << endl;
        return 1;
    }

    vector<string> words;
    string line;
    while (getline(inFile, line)) {
        words.push_back(line);
    }
    inFile.close();
    
    sort(words.begin(), words.end());

    ofstream sortedFile("sorted.txt");
    if (!sortedFile.is_open()) {
        cout << "Error creating sorted.txt" << endl;
        return 1;
    }

    for (const string& word : words) {
        sortedFile << word << endl;
    }
    sortedFile.close();

    cout << "Words sorted and saved to sorted.txt successfully." << endl;

    return 0;
}