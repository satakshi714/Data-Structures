#include<iostream>
using namespace std;

struct Book{
    int pop;
};
void swap(Book& a, Book& b){
    Book temp = a;
    a = b;
    b = temp;
}
void insertBook(Book heap[], int& heapSize, Book newBook){
    heapSize++;
    int i = heapSize - 1 ;
    heap[i] = newBook;

    while(i > 0 && heap[(i-1)/2].pop < heap[i].pop){
        swap(heap[i], heap[(i-1)/2]);
        i =(i-1)/2;
    }
}

void printHeap(Book heap[], int heapSize){
    for(int i = 0; i < heapSize; i++){
        cout<<heap[i].pop<<" ";
    }
}

int main(){
    Book maxHeap[100];
    int heapSize = 0;

    while(true){
        Book newBook;
        if(!(cin>>newBook.pop)){
            break;
        }
        if(heapSize < 100){
            insertBook(maxHeap, heapSize, newBook);
        }else{
            cout<<"Heap is full";
        }
    }
    printHeap(maxHeap, heapSize);
}