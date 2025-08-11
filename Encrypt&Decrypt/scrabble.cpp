#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool canMakeWord(const string& word, const string& letters) {
    string availableLetters = letters;
    string lowercaseWord = word;

    transform(lowercaseWord.begin(), lowercaseWord.end(), lowercaseWord.begin(), ::tolower);
    transform(availableLetters.begin(), availableLetters.end(), availableLetters.begin(), ::tolower);

    for (size_t i = 0; i < lowercaseWord.size(); ++i) {
        char c = lowercaseWord[i];
        string::iterator it = find(availableLetters.begin(), availableLetters.end(), c);
        if (it != availableLetters.end()) {
            availableLetters.erase(it); 
        } else {
            return false; 
        }
    }

    return true; 
}

int main(int argc, char* argv[]) {
    if (argc != 2 || !isalpha(*argv[1])) {
        cout << "USAGE: scrabble [letters]" << endl;
        return 1;
    }

    string letters = argv[1];

    string word;
    while (cin >> word) {
        bool valid = true;
        for (size_t i = 0; i < word.size(); ++i) {
            if (!isalpha(word[i])) {
                valid = false;
                break;
            }
        }
        if (!valid) {
            cout << "Invalid word." << endl;
            continue;
        }
        if (canMakeWord(word, letters)) {
            cout << word << ": Yes" << endl;
        } else {
            cout << word << ": No" << endl;
        }
    }

    return 0;
}