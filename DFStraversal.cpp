#include<iostream>
using namespace std;
#define MAX_VERTICES 100

void addEdge(int adj[MAX_VERTICES][MAX_VERTICES], int v, int w){
    adj[v][w] = 1;
}
void dfs(int adj[MAX_VERTICES][MAX_VERTICES], int visited[MAX_VERTICES], int V, int v){
    visited[v] = 1;
    cout<<v<<" ";
    for(int i = 0; i < V; ++i){
        if(adj[v][i] && !visited[i]){
            dfs(adj, visited, V, i);
        }
    }
}

int main(){
    int V, E;
    cin>>V>>E;
    int adj[MAX_VERTICES][MAX_VERTICES] = {0};
    int visited[MAX_VERTICES] = {0};
    for(int i = 0; i < E; i++){
        int v, w;
        cin>>v>>w;
        addEdge(adj, v, w);
    }
    int startVertex;
    cin>>startVertex;
    cout<<"DFS : ";
    dfs(adj,visited, V, startVertex);

    return 0;
}