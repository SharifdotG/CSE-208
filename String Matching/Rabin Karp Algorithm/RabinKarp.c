#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int calculateHash(char *str, int length) {
    int hashValue = 0;

    for (int i = 0; i < length; i++) {
        hashValue += str[i];
    }

    return hashValue;
}

void RabinKarp(char *text, char *pattern) {
    int textSize = strlen(text);
    int patternSize = strlen(pattern);

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
                printf("Pattern found at index %d\n", i);
            }
        }

        if (i < textSize - patternSize) {
            textHash -= text[i];
            textHash += text[i + patternSize];
        }
    }
}

int main() {
    char text[] = "AABAACAADAABAABA";
    char pattern[] = "AABA";

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