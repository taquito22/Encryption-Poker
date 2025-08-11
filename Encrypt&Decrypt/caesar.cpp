#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

string encryptCaesar(string text, int shift) {
    string result = "";
    for (size_t i = 0; i < text.size(); ++i) {
        char& c = text[i];
        if (isalpha(c)) {
            char start = islower(c) ? 'a' : 'A';
            c = start + (c - start + shift) % 26;
        }
        result += c;
    }
    return result;
}

string decryptCaesar(string text, int shift) {
    string result = "";
    for (size_t i = 0; i < text.size(); ++i) {
        char& c = text[i];
        if (isalpha(c)) {
            char start = islower(c) ? 'a' : 'A';
            int x = c - start - shift;
            c = start + (x + 26) % 26;
        }
        result += c;
    }
    return result;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "USAGE: caesar [-ed] [key]" << endl;
        return 1;
    }

    string operation = argv[1];
    int key;

    try {
        key = stoi(argv[2]) % 26; 
    } catch (...) {
        cout << "USAGE: caesar [-ed] [key]" << endl;
        return 1;
    }

    if (operation != "-e" && operation != "-d") {
        cout << "USAGE: caesar [-ed] [key]" << endl;
        return 1;
    }

    string line;
    while (getline(cin, line)) {
        if (operation == "-e") {
            cout << encryptCaesar(line, key) << endl;
        } else if (operation == "-d") {
            cout << decryptCaesar(line, key) << endl;
        }
        else{
            cerr << "USAGE: caesar [-ed] [key]" << endl;
        }
    }

    return 0;
}