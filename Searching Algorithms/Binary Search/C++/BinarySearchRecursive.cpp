#include <bits/stdc++.h>

using namespace std;

/**
 * Recursive implementation of binary search algorithm
 * @param array array to be searched
 * @param target element to be searched
 * @param left left index of the array
 * @param right right index of the array
 * @return index of the element if found, otherwise -1
 */
int binarySearch(int array[], int target, int left, int right) {
    if (right >= left) { // While there is at least one element in the array

        /**
         * I'm using the following formula to calculate the middle index
         * to avoid the possible integer overflow:
         * mid = left + (right - left) / 2
         */
        int mid = left + (right - left) / 2;

        // If element is present at the middle itself, return its index
        if (array[mid] == target) {
            return mid;
        }

        /**
         * If element is smaller than mid, then it can only be present
         * in left subarray
         */
        if (array[mid] > target) {
            return binarySearch(array, target, left, mid - 1);
        }

        // Else the element can only be present in right subarray
        return binarySearch(array, target, mid + 1, right);
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