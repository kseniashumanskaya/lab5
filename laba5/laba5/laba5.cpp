#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

const int space = 32;

int TheNumberOfWords(const char* str) {
    int TheNumberOfWords = 1;
    if (strlen(str) == 0) {
        TheNumberOfWords = 0;
    }
    else {
        if ((int)str[0] == space) {
            TheNumberOfWords = 0;
        }
        for (int i = 0; i < strlen(str) - 1; i++) {
            if (((int)str[i] == space) && ((int)str[i + 1] != space)) {
                TheNumberOfWords++;
            }
        }
    }

    return TheNumberOfWords;
}

void FillingVectorFromFile(vector<string>& str, ifstream& file) {
    while (file) {
        string string;
        getline(file, string);
        str.push_back(string);
    }
    file.close();
}

void FillingTheFirstFile(vector<string>& str, ofstream& file) {
    for (int i = 0; i < str.size(); i++) {
        const char* chr = str[i].c_str();
        if (TheNumberOfWords(chr) < 3) {
            file << str[i] << endl;
        }
    }
    file.close();
}

void FillingTheSecondFile(vector<string>& str, ofstream& file) {
    for (int i = 0; i < str.size(); i++) {
        const char* chr = str[i].c_str();
        if ((TheNumberOfWords(chr) > 2) && (TheNumberOfWords(chr) < 7)) {
            file << str[i] << endl;
        }
    }
    file.close();
}

int main() {
    ifstream inf("InputFile.txt");
    vector <string> str;
    FillingVectorFromFile(str, inf);
    ofstream outf1("outputFile1.txt");
    FillingTheFirstFile(str, outf1);
    ofstream outf2("outputFile2.txt");
    FillingTheSecondFile(str, outf2);
}