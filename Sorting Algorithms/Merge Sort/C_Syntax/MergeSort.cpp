#include <bits/stdc++.h>

using namespace std;

void merge(int array[], int left, int mid, int right) {
    int i, j, k;

    int range1 = mid - left + 1;
    int range2 = right - mid;

    int leftArray[range1], rightArray[range2];

    for (i = 0; i < range1; i++) {
        leftArray[i] = array[left + i];
    }

    for (j = 0; j < range2; j++) {
        rightArray[j] = array[mid + 1 + j];
    }

    i = 0, j = 0, k = left;

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