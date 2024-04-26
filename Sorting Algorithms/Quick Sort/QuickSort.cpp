#include <bits/stdc++.h>

using namespace std;

int partition(int array[], int left, int right) {
    int pivot = array[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (array[j] < pivot) {
            i++;
            swap(array[i], array[j]);
        }
    }

    swap(array[i + 1], array[right]);

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
    int size = sizeof(array) / sizeof(array[0]);

    quickSort(array, 0, size - 1);

    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    
    cout << endl;

    return 0;
}

/*
Input:
None

Output:
5 6 7 11 12 13
*/