#include<iostream>
using namespace std;

void minHeap(int arr[], int n, int i){
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if(left < n && arr[left] < arr[smallest]){
        smallest = left;
    }
    if(right < n && arr[right] < arr[smallest]){
        smallest = right;
    }
    if(smallest != i){
        swap(arr[i], arr[smallest]);
        minHeap(arr, n, smallest);
    }
}

void buildHeap(int arr[], int n){
    for(int i = n/2-1; i >= 0; i--){
        minHeap(arr, n, i);
    }
}


int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    buildHeap(arr, n);
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}