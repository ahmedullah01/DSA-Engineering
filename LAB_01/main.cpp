
#include <iostream>
using namespace std;

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.

void LinearSearch(int searchval) {
    int arr1[10] = {1,5,11,4,5,6,33,8,9};
    bool flag = false;
    for (int i = 0 ; i<10;i++) {
        if (arr1[i]==searchval ) {
            cout<<"found at "<<i<<endl;
            flag = true;

        }
    }
    if (flag == false) {
        cout<<" not found";
    }
}

void BinarySearch(int searchval)
{
    int arr2[10] = {1,2,3,3,3,6,7,8,9};
    int l = 0 ;
    int r = 9;
    int mid = 0;

    if (l>r) {
        cout<<"notfound";
    }
    while (l<=r) {

        mid = (l + r)/2;



        if (searchval == arr2[mid]) {
            int checker = mid;
            cout<<"found at "<<mid<<endl;
            while (arr2[checker-1] == searchval && checker-1 >=0  ) {
                cout<<"found at "<<checker-1<<endl;
                checker--;
            }
            while (arr2[checker+1] == searchval && checker+1 <=9 ) {
                cout<<"found at "<<checker+1<<endl;
                checker++;
            }
            break;

        }

        if (searchval > arr2[mid]) {
            l = mid+1;
        }

        if (searchval < arr2[mid]) {
            r = mid-1;
        }


    }
}

int main() {

 // LinearSearch(5);
BinarySearch(3);

    };
