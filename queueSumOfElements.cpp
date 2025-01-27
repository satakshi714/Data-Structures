#include<iostream>
using namespace std;

struct Node{
    int data;
    int count;
    Node* next;
};
Node* head = NULL;
Node* tail = NULL;
void enqueue(int data){
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    if(newNode){
        Node* temp = head;
        if(head == NULL && tail == NULL){
            head = tail = newNode;
        }
        tail->next=newNode;
        tail = newNode;
    }else{
        cout<<"Queue Underflow";
    }
}

int sum(int data){
    int sum = 0;
    Node* temp = head;
    while(temp != NULL){
        sum = sum + temp->data;
        temp = temp->next;
    }
    return sum;
}

int main(){
    int n, data;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>data;
        enqueue(data);
    }
    cout<<"Sum of queue: "<<sum(data);
    return 0;
}