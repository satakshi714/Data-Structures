#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};
Node* createNode(int value){
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data){
    if(root == NULL){
        return createNode(data);
    }
    if(data < root ->data){
        root->left = insert(root->left, data);
    }else{
        root->right = insert(root->right, data);
    }
    return root;
}
void postOrder(Node* root){
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<< root->data<<" ";
}

int main(){
    Node* root = NULL;
    int n, data;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>data;
        root = insert(root, data);
    }
    postOrder(root);
    return 0;
}