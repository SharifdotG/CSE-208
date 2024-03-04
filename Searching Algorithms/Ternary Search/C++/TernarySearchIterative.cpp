#include <bits/stdc++.h>

using namespace std;

int ternarySearch(int array[], int target, int left, int right) {
    while (right >= left) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        if (target == array[mid1]) {
            return mid1;
        }

        if (target == array[mid2]) {
            return mid2;
        }

        if (target < array[mid1]) {
            right = mid1 - 1;
        } else if (target > array[mid2]) {
            left = mid2 + 1;
        } else {
            left = mid1 + 1;
            right = mid2 - 1;
        }
    }

    return -1;
}

int main() {
    int array[] = {1, 3, 5, 7, 9};
    int arraySize = sizeof(array) / sizeof(array[0]);
    int target = 7;

    int result = ternarySearch(array, target, 0, arraySize - 1);

    if (result == -1) {
        cout << "Element not found in the array" << endl;
    } else {
        cout << "Element found at index " << result << endl;
    }

    return 0;
}