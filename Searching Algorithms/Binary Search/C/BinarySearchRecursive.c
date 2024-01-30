#include <stdio.h>

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

/**
 * Bubble Sort algorithm implementation
 * @param array array to be sorted
 * @param size size of the array
 */
void bubbleSort(int array[], int size) {
    /**
     * Running two loops: one to iterate over the array
     * and the other to keep track on the number of
     * iterations performed
     */
    for (int step = 0; step < size - 1; ++step) {
        for (int i = 0; i < size - step - 1; ++i) {
            if (array[i] > array[i + 1]) {

                /**
                 * Swapping elements if they are not in the intended order:
                 *  - array[i] is greater than the next element
                 *  - Swapping it
                 *  - Otherwise skipping to next element
                 */
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
    scanf("%d", &target);;

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