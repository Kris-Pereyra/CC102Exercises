#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool isPalindrome(string word) {
    int start = 0, end = word.length() - 1;
    while (start < end) {
        if (word[start] != word[end])
            return false;
        start++;
        end--;
    }
    return true;
}

int main() {
    ifstream file("WORDS.TXT");
    string word;
    int count = 0;

    while (file >> word) {
        if (isPalindrome(word))
            count++;
    }

    cout << "Palindrome words: " << count;

    file.close();
    return 0;
}