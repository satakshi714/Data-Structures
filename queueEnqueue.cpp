#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
Node* head = NULL;
Node* tail = NULL;

void enqueue(int data){
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    if(newNode){
        if(head == NULL && tail == NULL){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }else{
        cout<<"Queue overflow";
    }
}

void display(){
    if(head == NULL && tail == NULL){
        cout<<"Queue underflow";
    }
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    int n, data;
    cout<<"Enter the eleme nts to be inserted: ";
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>data;
        enqueue(data);
    }
    cout<<"The queue is: ";
    display();
    return 0;
}