#include <bits/stdc++.h>

using namespace std;

/**
 * Iterative implementation of binary search algorithm
 * @param array array to be searched
 * @param target element to be searched
 * @param left left index of the array
 * @param right right index of the array
 * @return index of the element if found, otherwise -1
 */
int binarySearch(int array[], int target, int left, int right) {
    while (left <= right) {

        /**
         * We are using following formula for calculating mid index
         * to avoid integer overflow:
         * mid = left + (right - left) / 2
         */
        int mid = left + (right - left) / 2;

        // Checking if target is present at middle index
        if (array[mid] == target) {
            return mid;
        }

        /**
         * If target is greater, ignore left half
         * of the array, otherwise ignore right half
         */
        if (array[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
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
     * Calling binarySearch function to find the index of the element
     * in the array
     */
    int result = binarySearch(array, target, 0, arraySize - 1);

    /**
     * If result is -1, then the element is not present in the array,
     * otherwise the element is present and the value of result will
     * be the index of the element in the array
     */
    if (result == -1) {
        cout << "Element not found in the array" << endl;
    } else {
        cout << "Element found at index " << result << endl;
    }

    return 0;
}