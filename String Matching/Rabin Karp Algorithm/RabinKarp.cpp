#include <bits/stdc++.h>

using namespace std;

int calculateHash(string str, int length) {
    int hashValue = 0;

    for (int i = 0; i < length; i++) {
        hashValue += str[i];
    }

    return hashValue;
}

void RabinKarp(string text, string pattern) {
    int textSize = text.length();
    int patternSize = pattern.length();

    int patternHash = calculateHash(pattern, patternSize);
    int textHash = calculateHash(text, patternSize);

    for (int i = 0; i <= textSize - patternSize; i++) {
        if (patternHash == textHash) {
            bool found = true;

            for (int j = 0; j < patternSize; j++) {
                if (text[i + j] != pattern[j]) {
                    found = false;
                    break;
                }
            }

            if (found) {
                cout << "Pattern found at index " << i << endl;
            }
        }

        if (i < textSize - patternSize) {
            textHash -= text[i];
            textHash += text[i + patternSize];
        }
    }
}

int main() {
    string text = "AABAACAADAABAABA";
    string pattern = "AABA";

    RabinKarp(text, pattern);

    return 0;
}

/*
Input:
None

Output:
Pattern found at index 0
Pattern found at index 9
Pattern found at index 12
*/