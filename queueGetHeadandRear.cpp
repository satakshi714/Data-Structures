#include<iostream>
#include<queue>
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
    }
    tail->next = newNode;
    tail = newNode;
    }else{
        cout<<"Queue is empty";
    }
}
int getFront(){
    if(head != NULL){
        return head->data;
    }return -1;
}
int getRear(){
    if(tail != NULL){
        return tail->data;
    }return -1;
}
int main(){
    int n, data;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>data;
        enqueue(data);
    }
    cout<<"Front Element: ";
    cout<<getFront();
    cout<<endl;
    cout<<"Rear Element: ";
    cout<<getRear();

}