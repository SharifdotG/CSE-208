#include <stdio.h>

void merge(int array[], int left, int mid, int right) {
    int range1 = mid - left + 1;
    int range2 = right - mid;

    int leftArray[range1], rightArray[range2];

    for (int i = 0; i < range1; i++) {
        leftArray[i] = array[left + i];
    }

    for (int j = 0; j < range2; j++) {
        rightArray[j] = array[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < range1 && j < range2) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        } else {
            array[k] = rightArray[j];
            j++;
        }

        k++;
    }

    while (i < range1) {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < range2) {
        array[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(int array[], int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    mergeSort(array, left, mid);
    mergeSort(array, mid + 1, right);

    merge(array, left, mid, right);
}

int main() {
    int array[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(array) / sizeof(array[0]);

    mergeSort(array, 0, size - 1);

    for (int i = 0; i < size; i++) {
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
>>>>>>> 95d70b4281018478501f4e0d5cc6ca409c62ae3d:Sorting Algorithms/Merge Sort/MergeSort.c
