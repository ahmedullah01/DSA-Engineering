#include <iostream>
using namespace std;

class selectionsort{
public:
    int arr[5];
    void sorting() {
        arr[0] = 2;
        arr[1] = 4;
        arr[2] = 1;
        arr[3] = 3;
        arr[4] = 9;
for (int i = 0 ; i < 4 ; i++) {
    int min = i;
    for (int j = i+1 ; j<5 ;j++) {
        if (arr[min] > arr[j]) {
            min = j;
        }
    }
    int temp = arr[i];
    arr[i] = arr[min];
    arr[min] = temp;
}

        for (int i  = 0 ; i < 5 ; i++) {
            cout<<arr[i];
        }

    }


};

int main() {
selectionsort *s = new selectionsort();
    s ->sorting();
}