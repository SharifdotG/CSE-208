#include <bits/stdc++.h>

using namespace std;

/**
 * Recursive implementation of ternary search algorithm
 * @param array array to be searched
 * @param target element to be searched
 * @param left left index of the array
 * @param right right index of the array
 * @return index of the element if found, otherwise -1
 */
int ternarySearch(int array[], int target, int left, int right) {
    if (right >= left) { // While there is at least one element in the array

        /**
         * I'm using the following formulas for calculating mid1 and mid2 index
         * to avoid integer overflow:
         * mid1 = left + (right - left) / 3
         * mid2 = right - (right - left) / 3
         */
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        // Checking if target is present at mid1 index
        if (array[mid1] == target) {
            return mid1;
        }

        // Checking if target is present at mid2 index
        if (array[mid2] == target) {
            return mid2;
        }

        /**
         * If target is smaller than element at mid1 index,
         * ignore right third of the array, otherwise if
         * target is greater than element at mid2 index,
         * ignore left third of the array and make a recursive
         * call on the remaining third of the array
         */
        if (target < array[mid1]) {
            return ternarySearch(array, target, left, mid1 - 1);
        } else if (target > array[mid2]) {
            return ternarySearch(array, target, mid2 + 1, right);
        } else {
            return ternarySearch(array, target, mid1 + 1, mid2 - 1);
        }
    }

    return -1; // element not found
}

int main() {
    int arraySize;
    cout << "Enter the size of the array: ";
    cin >> arraySize;

    int array[arraySize];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < arraySize; i++) {
        cin >> array[i];
    }

    cout << "Sorting the array..." << endl;
    sort(array, array + arraySize);

    cout << "Sorted array: ";
    for (int i = 0; i < arraySize; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    int target;
    cout << "Enter the element to be searched: ";
    cin >> target;

    /**
     * Passing arraySize - 1 as the right parameter because
     * array index starts from 0 and not 1. If we pass arraySize
     * instead of arraySize - 1, we will get an error
     */
    int result = ternarySearch(array, target, 0, arraySize - 1);

    if (result == -1) {
        cout << "Element not found" << endl;
    } else {
        cout << "Element found at index " << result << endl;
    }

    return 0;
}