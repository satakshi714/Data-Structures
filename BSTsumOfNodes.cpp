#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data){
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data){
    if(root == NULL){
        return createNode(data);
    }
    if(data < root->data){
        root->left = insert(root->left, data);
    }else{
        root->right= insert(root->right, data);
    }
    return root;
}

int add(Node* root){
    if(root == NULL){
        return 0;
    }
    return(root->data + add(root->left) + add(root->right));
}

int main(){
    Node* root = NULL;
    int data;
    do{
        cin>>data;
        if(data > 0){
            root = insert(root, data);
        }
    }
    while(data != -1);
    int sum = add(root);
    cout<<sum;
}

