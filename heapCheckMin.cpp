#include<iostream>
using namespace std;

bool minHeap(int arr[], int n){
    for(int i = 0; i < n; i++){
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if(left < n && arr[left] < arr[i]){
            return false;
        }
        if(right < n && arr[right] < arr[i]){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    if(minHeap(arr, n) == 1){
        cout<<"Min heap";
    }else{
        cout<<"Not Min heap";
    }
    return 0;
}