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

void deleteMax(int arr[], int &n){
    arr[0] = arr[n-1];
    --n;
    maxHeap(arr, n, 0);
}
void displayOcc(int arr[], int &n){
    int max = arr[0];
    while(n > 0 && arr[0] == max){
        deleteMax(arr, n);
    }
}
int main(){
    int n;
    cin>>n;
    int  arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    buildHeap(arr, n);
    displayOcc(arr, n);
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;

}