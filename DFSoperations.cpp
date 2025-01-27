#include<iostream>
using namespace std;
const int MAX_NODES = 100;
void addEdge(int adj[MAX_NODES][MAX_NODES], int u, int v){
    adj[v][u] = 1;
}
bool pathInDFS(int adj[MAX_NODES][MAX_NODES], int visited[MAX_NODES], int V, int start, int end, int path[MAX_NODES], int &pathLength){
    visited[start] = 1;
    path[pathLength++] = start;
    if(start == end){
        return true;
    }
    for(int i = 0; i < V; ++i){
        if(adj[start][i] && !visited[i]){
            if(pathInDFS(adj, visited, V, i, end, path, pathLength)){
                return true;
            }
        }
    }
    pathLength--;
    return false;
}

int main(){
    int V, E;
    cout<<"Enter vertices and Edges: ";
    cin>>V>>E;

    int adj[MAX_NODES][MAX_NODES] = {0};
    int visited[MAX_NODES] = {0};
    int path[MAX_NODES];
    int pathLength = 0;

    for(int i = 0; i < E; i++){
        int v, u;
        cin>>v>>u;
        addEdge(adj, v, u);
    }
            int sVertex, eVertex;
            cin>>sVertex>>eVertex;
            if(pathInDFS(adj, visited, V, sVertex, eVertex, path, pathLength)){
                for(int i = sVertex; i < eVertex; ++i){
                    cout<<path[i]<<" ";
                }
                cout<<"Path length is: "<<pathLength;
            }else{
                cout<<"Path not found";
            }



return 0;   
}