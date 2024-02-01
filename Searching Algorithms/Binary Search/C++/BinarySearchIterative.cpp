#include <bits/stdc++.h>

using namespace std;

int binarySearch(int array[], int target, int left, int right) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (target == array[mid]) {
            return mid;
        }

        if (target > array[mid]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    int array[] = {1, 3, 5, 7, 9};
    int arraySize = sizeof(array) / sizeof(array[0]);
    int target = 7;

    int result = binarySearch(array, target, 0, arraySize - 1);

    if (result == -1) {
        cout << "Element not found in the array" << endl;
    } else {
        cout << "Element found at index " << result << endl;
    }

    return 0;
}