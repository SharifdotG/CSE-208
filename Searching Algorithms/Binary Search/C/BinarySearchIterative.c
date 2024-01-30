#include <stdio.h>

/**
 * Iterative implementation of binary search algorithm
 * @param array array to be searched
 * @param target element to be searched
 * @param left left index of the array
 * @param right right index of the array
 * @return index of the element if found, otherwise -1
 */
int binarySearch(int array[], int target, int left, int right) {
    while (left <= right) { // While there is at least one element in the array

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
         * of the array
         */
        if (array[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // element not found
}

void bubbleSort(int array[], int size) {
    for (int step = 0; step < size - 1; ++step) {
        for (int i = 0; i < size - step - 1; ++i) {

            // To sort in descending order, change">" to "<".
            if (array[i] > array[i + 1]) {

                // swap if greater is at the rear position
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}

int main() {
    int arraySize;
    printf("Enter the size of the array: ");
    scanf("%d", &arraySize);

    int array[arraySize];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < arraySize; i++) {
        scanf("%d", &array[i]);
    }

    printf("Sorting the array...\n");
    bubbleSort(array, arraySize);

    printf("Sorted array: ");
    for (int i = 0; i < arraySize; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");

    int target;
    printf("Enter the element to be searched: ");
    scanf("%d", &target);

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
        printf("Element not found in the array\n");
    } else {
        printf("Element found at index %d\n", result);
    }

    return 0;
}