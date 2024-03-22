<<<<<<< HEAD:Searching Algorithms/Binary Search/C++/BinarySearchRecursive.cpp
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
        cout << "Element not found in the array" << endl;
    } else {
        cout << "Element found at index " << result << endl;
    }

    return 0;
}
=======
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
        cout << "Element not found in the array" << endl;
    } else {
        cout << "Element found at index " << result << endl;
    }

    return 0;
}

/*
Output:
Element found at index 3
*/
>>>>>>> 95d70b4281018478501f4e0d5cc6ca409c62ae3d:Searching Algorithms/Binary Search/BinarySearch.cpp
