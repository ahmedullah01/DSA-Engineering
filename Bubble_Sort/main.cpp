#include <iostream>
using namespace std;




void bubble_sort() {
    int arr[] = {2 ,4 ,1,3,9};
    for (int i = 0 ; i < 5-1 ; i++) {
        for (int j =0 ; j<5-1-i ; j++ ) {
            if (arr[j]>arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }

    }

    for (int i = 0 ; i < 5 ; i++) {
        cout<<arr[i];
    }
}



int main() {
bubble_sort();
}