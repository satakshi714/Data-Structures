#include<iostream>
using namespace std;
const int MAX_NODES = 100;

void addEdge(int adj[MAX_NODES][MAX_NODES], int u, int v){
    adj[u][v] = 1;
}

bool bfs(int adj[MAX_NODES][MAX_NODES], int visited[MAX_NODES], int parent[MAX_NODES], int V, int start, int end, int &pathLength){
    int queue[MAX_NODES];
    int front = -1, rear = -1;

    queue[++rear] = start;
    visited[start] = 1;
    parent[start] = -1;

    while(front != rear){
        int current = queue[++front];

       if(current == end){
        int node = end;
        while(node != start){
            pathLength++;
            node = parent[node];
        }
        return true;
       }
       for (int i = 0; i < V; ++i){
        if(adj[current][i] == 1 && !visited[i]){
            queue[++rear] = i;
            visited[i] = 1;
            parent[i] = current;
        }
       }
    }
    return false;
}

int main(){
    int V, E;
    cin>>V>>E;

    int adj[MAX_NODES][MAX_NODES] = {0};
    int visited[MAX_NODES] = {0};
    int parent[MAX_NODES] = {0};
    int pathLength = 0;

    for(int i = 0; i < E; ++i){
        int u, v;
        cin>>u>>v;
        addEdge(adj, u ,v);
    }
    int start, end;
    cin>>start>>end;

    if(bfs(adj, visited, parent, V, start, end, pathLength)){
        cout<<"path length is: "<<pathLength;
    }else{
        cout<<"No path found";
    }
    return 0;
}