#include<iostream>
#include<algorithm>
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

void heapSort(int arr[], int n){
    buildHeap(arr, n);
    for(int i = n-1; i >= 0; i--){
        swap(arr[0], arr[i]);
        minHeap(arr, n, 0);
    }
}

int main(){
    int n1, n2, n3;
    cin>>n1;
    int arr[20];
    for(int i = 0; i < n1; i++){
        cin>>arr[i];
    }
    cin>>n2;
    for(int i = n1; i < (n1 + n2); i++){
        cin>>arr[i];
    }
    cin>>n3;
    for(int i = n1 + n2; i < (n1 + n2 + n3); i++){
        cin>>arr[i];
    }
    int total = n1 + n2 + n3;
    heapSort(arr, total);
    sort(arr, arr + total);
    for(int i = 0; i < total; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}