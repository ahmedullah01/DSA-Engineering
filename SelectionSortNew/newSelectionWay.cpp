#include <iostream>
using namespace std;

int arr[5] = {3,2,7,1,5};

void sort(){
    for(int i = 0 ;i<=3;i++){

for(int j = i+1;j<5;j++){
    if(arr[j] > arr[i]){//2<3
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;    
    }
}
    }

}
int main()
{
    sort();
    for(int i = 0;i<5;i++){
        cout<<arr[i]<<" ";
    }
}