#include<iostream>
using namespace std;
const int MAX_NODES = 100;
void addEdge(int adj[MAX_NODES][MAX_NODES], int v, int w){
    adj[v][w] = 1;
}
bool dfs(int adj[MAX_NODES][MAX_NODES], int visited[MAX_NODES], int V, int start, int end, int path[MAX_NODES], int &pathLength){
    visited[start] = 1;
    path[pathLength++] = start;

    if(start == end){
        return true;
    }
    for(int i = 0; i < V; ++i){
        if(adj[start][i]  == 1 && !visited[i]){
            if(dfs(adj, visited, V, i, end, path, pathLength)){
                return true;
            }
        }
    }
    pathLength--;
    return false;
}

int main(){
    int V, E;
    cin>>V;
    int adj[MAX_NODES][MAX_NODES] = {0};
    int visited[MAX_NODES] = {0};
    int path[MAX_NODES];
    int pathLength = 0;

    
    cin>>E;
    for(int i = 0; i < E; ++i){
        int u, v;
        cin>>u>>v;
        addEdge(adj, u, v);
    }
    int sVertex, eVertex;
    cin>>sVertex;
    cin>>eVertex;

    cout<<"DFS path between "<<sVertex<<" and "<<eVertex<<" is: ";
    if(dfs(adj, visited, V, sVertex, eVertex, path, pathLength)){
        for(int i = 0; i < pathLength; ++i){
            cout<<path[i]<<" ";
        }
        cout<<endl;
        cout<<"Path length is: "<<pathLength<<endl;
    }else{
        cout<<"No path found";
    }
    return 0;
}