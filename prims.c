#include <stdio.h>
#define m 100
#define inf 999
int adj[m][m];      // Adjacency matrix
int visited[m]; 
int n;
int findkey(int key[],int visited[]){
    int min=inf,min_index=-1;
    for(int i=0;i<n;i++){
        if(!visited[i] && key[i]<min){
            min=key[i];
            min_index=i;
        }
    }
    return min_index;
}
void prims(){
    int parent[n];
    int key[n];
    for(int i=0;i<n;i++){
            key[i]=inf;
    }
    key[0]=0;
    parent[0]=-1;

    for(int i=0;i<n;i++){
        int u=findkey(key,visited);
        visited[u]=1;
        for(int v=0;v<n;v++){
            if(adj[u][v] && !visited[v] && adj[u][v] < key[v] ){
                parent[v]=u;
                key[v]=adj[u][v];
            }
        }
    }
    printf("Edge \tWeight\n");
    int totalCost = 0;
    for (int i = 1; i < n; i++) {
        printf("%d - %d \t%d\n", parent[i], i, adj[i][parent[i]]);
        totalCost += adj[i][parent[i]];
    }
    printf("Total cost of MST: %d\n", totalCost);


}
int main() {
    int  e, u, v, start,w;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);

    // Initialize adjacency matrix and visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter %d edges (u v):\n", e);
    for (int i = 0; i < e; i++) {
        scanf("%d %d%d", &u, &v,&w);
        adj[u][v] = w;
        adj[v][u] = w; // Because it's an undirected graph
    }



  prims();

    return 0;
}