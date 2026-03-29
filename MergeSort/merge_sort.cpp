#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



void merge(vector<int> &arr , int st ,int mid ,int end){

 vector<int> temp;
int i  = st ;
int j = mid + 1;
while(i<=mid && j<=end){
    if(arr[i]  <= arr[j]){
        temp.push_back(arr[i]);
        i++;
    }
    else{
        temp.push_back(arr[j]);
        j++;
    }
}

while(i<=mid){
    temp.push_back(arr[i]);
    i++;
}
while(j<=end){
    temp.push_back(arr[j]);
    j++;
}

for(int i  = 0 ; i < temp.size() ; i++){
    arr[i+st] = temp[i];
}

}

void mergeSort(vector<int> &arr , int st , int end){
if(st<end){
    int mid  = (st + end)/2;
    mergeSort(arr,st ,mid);
    mergeSort(arr,mid+1,end);
    
    merge(arr,st,mid,end);
}

}




int main(){

    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    mergeSort(arr, 0, arr.size() - 1);



    for(int i = 0 ; i < arr.size() ; i++){
        cout<<arr[i]<<" ";
    }
}
// ...existing code...