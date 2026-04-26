#include<iostream>
using namespace std;

 int size = 3;
 int orignalsize = 3;
    int array[3] = {10 , 20 ,5 };
void upHeapify(int arr[], int index) {
    while(index > 0) {
        int parent = (index - 1) / 2;

        if(arr[index] > arr[parent]) {
            swap(arr[index], arr[parent]);
            index = parent;
        }
        else {
            break;
        }
    }
}
void DoHeapify(int arr[], int index) {
    while(index > 0) {
        int parent = (index - 1) / 2;

        if(arr[index] < arr[parent]) {
            swap(arr[index], arr[parent]);
            index = parent;
        }
        else {
            break;
        }
    }
}


void DoHeapifyRecurrsion(int arr[] , int index){
    if(index == 0){
        return;
    }
    int parent = (index - 1) / 2;

    if(arr[index] < arr[parent]) {
        swap(arr[index], arr[parent]);
        DoHeapifyRecurrsion(arr, parent);
    }else {
        return;
    }
}

void upHeapifyRecurrsion(int arr[] , int index){
    if(index == 0){
        return;
    }
    int parent = (index - 1) / 2;

    if(arr[index] > arr[parent]) {
        swap(arr[index], arr[parent]);
        upHeapifyRecurrsion(arr, parent);
    }else {
        return;
    }
}

void Delete(int arr[],int &size)
{
    if(size== 0 )
{
    cout<<"Heap is empty"<<endl;

}
size = size-1;
int temp = arr[0];
arr[0] = arr[size];
// cout<<arr[0]<<endl;
arr[size] = temp;
}

int main()
{
   
    
upHeapifyRecurrsion(array, orignalsize-1);


// cout<<size;
  for(int i=0; i<orignalsize; i++){
      cout<<array[i]<<" ";
  }
}