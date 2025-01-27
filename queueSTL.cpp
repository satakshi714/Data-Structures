#include<iostream>
#include<queue>
using namespace std;

    void del(queue<int>& q, int index){
        queue<int> temp;
        int size = q.size();
        for(int i = 0; i < size; i++){
            if(i != index){
                temp.push(q.front());
            }
            q.pop();
        }
    }

    int main(){
    queue<int> q;
    int n, data;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>data;
        q.push(data);
    }
    int index;
    cin>>index;
    del(q,index);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}
