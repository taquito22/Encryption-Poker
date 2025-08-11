#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

string capF(const string& str) {
    string result = str;
    if (!result.empty()) {
        result[0] = toupper(result[0]);
    }
    return result;
}

char substitute(char ch, const string& key, bool encrypt) {
    if (isalpha(ch)) {
        int index = tolower(ch) - 'a'; 
        if (!encrypt) {
            size_t pos = key.find(tolower(ch));
            if (pos == string::npos) 
                return ch;
            return isupper(ch) ? toupper('a' + pos) : 'a' + pos; 
        }

        char substituteChar = key[index];
        return isupper(ch) ? toupper(substituteChar) : substituteChar;
    }
    return ch; 
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "USAGE: substitution [-ed] [key]" << endl;
        return 1;
    }

    bool encrypt;
    string key = argv[2];
    if (string(argv[1]) == "-e")
        encrypt = true;
    else if (string(argv[1]) == "-d")
        encrypt = false;
    else {
        cout << "USAGE: substitution [-ed] [key]" << endl;
        return 1;
    }

    if (key.length() != 26) {
        cout << "USAGE: substitution [-ed] [key]" << endl;
        return 1;
    }

    transform(key.begin(), key.end(), key.begin(), ::tolower);
    for (char ch = 'a'; ch <= 'z'; ++ch) {
        if (key.find(ch) == string::npos) {
            cout << "USAGE: substitution [-ed] [key]" << endl;
            return 1;
        }
    }

    string line;
    while (getline(cin, line)) {
        for (size_t i = 0; i < line.length(); ++i) {
            char& ch = line[i];
            ch = substitute(ch, key, encrypt);
        }
        cout << line << endl;
    }

    return 0;
}