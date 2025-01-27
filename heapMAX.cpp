#include<iostream>
using namespace std;

void maxHeap(int arr[], int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }
    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }
    if(largest != i){
        swap(arr[i], arr[largest]);
        maxHeap(arr, n, largest);
    }
}

void buildHeap(int arr[], int n){
    for(int i = n/2-1; i >= 0; --i){
        maxHeap(arr, n, i);
    }
}

int main(){
    int n, arr[n];
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    buildHeap(arr, n);
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;

}