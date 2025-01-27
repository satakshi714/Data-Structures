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
        root->right = insert(root->right, data);
    }
    return root;
}

int sum(Node* root, int tgt){
    if(root == NULL){
        return 0;
    }
    if(root->data > tgt){
        return root->data + sum(root->left, tgt) + sum(root->right, tgt);
    }else{
        return sum(root->right, tgt);
    }
}

int main(){
    Node* root = NULL;
    int n, data;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>data;
        root = insert(root, data);
    }
    int tgt;
    cin>>tgt;
    cout<<sum(root, tgt);
    return 0;
}