#include <stdio.h>

int partition(int array[], int left, int right) {
    int pivot = array[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (array[j] < pivot) {
            i++;
            
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    int temp = array[i + 1];
    array[i + 1] = array[right];
    array[right] = temp;

    return i + 1;
}

void quickSort(int array[], int left, int right) {
    if (left >= right) {
        return;
    }

    int pivot = partition(array, left, right);

    quickSort(array, left, pivot - 1);
    quickSort(array, pivot + 1, right);
}

int main() {
    int array[] = {12, 11, 13, 5, 6, 7};
    int arraySize = sizeof(array) / sizeof(array[0]);

    quickSort(array, 0, arraySize - 1);

    for (int i = 0; i < arraySize; i++) {
        printf("%d ", array[i]);
    }
    
    printf("\n");

    return 0;
}

/*
Input:
None

Output:
5 6 7 11 12 13
*/