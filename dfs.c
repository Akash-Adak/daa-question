#include <stdio.h>
#define m 100
int adj[m][m];      // Adjacency matrix
int visited[m];     // Visited array
void dfs(int start, int n) {
    visited[start] = 1;
    printf("%d ", start);
    for (int v = 0; v < n; v++) {
        if (adj[start][v] == 1 && !visited[v]) {
            dfs(v, n);
        }
    }
}
int main() {
    int n, e, u, v, start;

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
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // Because it's an undirected graph
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    dfs(start, n);

    return 0;
}
