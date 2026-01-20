#include <iostream>
#include "SortingInsertion.h"
using namespace std;

void SortingInsertion::sorting() {
    int arr[] = {6, 1, 7, 4, 2};
    int n = 5;

    // Insertion Sort logic
    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && temp < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }

    // Print sorted array
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
