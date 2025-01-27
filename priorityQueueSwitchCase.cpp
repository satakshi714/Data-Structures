#include<iostream>
using namespace std;

struct Node{
    string data;
    int priority;
    Node* next;
};

Node* head = NULL;

void enqueue(string data, int priority){
    Node* newNode = new Node;
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;

    if(head == NULL || priority < head->priority){
        newNode->next = head;
        head = newNode;
    }
    else{
        Node* temp = head;
        while(temp->next != NULL && temp->next->priority <= priority){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void dequeue(){
    if(head == NULL){
        cout<<"Error: Queue is empty."<<endl;
    }
    else{
        Node* temp = head;
        cout<<"Patient with priority "<<temp->priority<<" and name "<<temp->data<<" has been treated."<<endl;
        head = temp->next;
        delete temp;
    }
}

int main(){
    int n, priority;
    string data;
    while(true){
        cin>>n;
        switch(n){
            case 1: 
                cin>>priority;
                cin>>data;
                enqueue(data,priority);
                break;
            case 2:
                dequeue();
                break;
            case 0:
                return 0;
            default:
                cout<<"Invalid choice."<<endl;
        }
    }
}
