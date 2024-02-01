#include <bits/stdc++.h>

using namespace std;

int binarySearch(int array[], int target, int left, int right) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        if (target == array[mid]) {
            return mid;
        }

        if (target < array[mid]) {
            return binarySearch(array, target, left, mid - 1);
        } else {
            return binarySearch(array, target, mid + 1, right);
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
        printf("Element not found in the array\n");
    } else {
        printf("Element found at index %d\n", result);
    }

    return 0;
}