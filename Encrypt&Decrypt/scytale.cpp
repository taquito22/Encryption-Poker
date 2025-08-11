#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

string scytaleEncrypt(const string& text, int key) {
    string result = "";
    int len = text.size();
    int cols = (len + key - 1) / key;

    for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < key; ++j) {
            int index = i + j * cols;
            if (index < len)
                result += text[index];
            else
                result += ' '; 
        }
    }

    return result;
}

string scytaleDecrypt(const string& text, int key) {
    string result = "";
    int len = text.size();
    int cols = (len + key - 1) / key;

    vector<vector<char> > grid(key, vector<char>(cols, ' '));

    int index = 0;
    for (int j = 0; j < cols; ++j) {
        for (int i = 0; i < key; ++i) {
            if (index < len) {
                grid[i][j] = text[index++];
            }
        }
    }

    for (int i = 0; i < key; ++i) {
        for (int j = 0; j < cols; ++j) {
            result += grid[i][j];
        }
    }

    return result;
}

int main(int argc, char* argv[]) {
    if (argc != 3 || argv[2][0] < '1') {
        cout << "USAGE: scytale [-ed] [key]" << endl;
        return 1;
    }

    string option = argv[1];
    int key = atoi(argv[2]);

    if ((option != "-e" && option != "-d") || key <= 0) {
        cout << "USAGE: scytale [-ed] [key]" << endl;
        return 1;
    }

    string line;
    while (getline(cin, line)) {
        if (option == "-e") {
            cout << scytaleEncrypt(line, key) << endl;
        } else {
            cout << scytaleDecrypt(line, key) << endl;
        }
    }

    return 0;
}