#include<iostream>
#include<stack>
using namespace std;

stack<int> s;

void push(){
    int data;
    cin>>data;
    s.push(data);
}

void pop(){
    if(s.empty()){
        cout<<"empty";
    }else{
        int item = s.top();
        s.pop();
    }
    cout<<endl;
}
void peek(){
    if(s.empty()){
        cout<<"empty";
    }else{
        s.top();
    }
}
void display(){
    if(s.empty()){
        cout<<"empty";
    }else{
        stack<int> temp = s;
        while(!temp.empty()){
            cout<<temp.top()<<" ";
        }
        temp.pop();
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    while(n){
        int c;
        cin>>c;
        switch(c){
            case 1: 
            push();
            break;
            case 2: 
            pop();
            break;
            case 3:
            display();
            break;
            case 4:
            peek();
            break;
            
        }
    }
}
