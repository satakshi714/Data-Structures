#include<iostream>
using namespace std;
const int MAX_NODES = 100;

void addEdge(int graph[MAX_NODES][MAX_NODES], int u, int v){
    graph[u][v] = 1;
    graph[v][u] = 1;
}
void bfs(int graph[MAX_NODES][MAX_NODES], int visited[MAX_NODES], int vertices, int start){
    int queue[MAX_NODES];
    int front = -1, rear = -1;

    queue[++rear] = start;
    visited[start] = 1;

    while(front != rear){
        int current = queue[++front] ;
        cout<<current<<" ";

        for(int i = 0; i < vertices; ++i){
            if(graph[current][i] == 1 && !visited[i]){
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}
int main(){
    int V, E;
    cin>>V;
    int graph[MAX_NODES][MAX_NODES] = {0};
    int visited[MAX_NODES] = {0};

    cin>>E;
    for(int i = 0; i < E; ++i){
        int u, v;
        cin>>u>>v;
        addEdge(graph, u ,v);
    }
    int startVertex;
    cin>>startVertex;
    cout<<"BFS: ";
    bfs(graph, visited, V, startVertex);
    return 0;
}