#include <stdio.h>
#define m 100
#define inf 999

int adj[m][m];     
int dist[m];        
int visited[m];     
int n;

int findMinDistance() {
    int min = inf, min_index = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void dijkstra(int start) {
    for (int i = 0; i < n; i++) {
        dist[i] = inf;
        visited[i] = 0;
    }
    dist[start] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = findMinDistance();
        if (u == -1) break;
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (adj[u][v] && !visited[v] && dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }

    printf("\nVertex\tShortest Distance from %d\n", start);
    for (int i = 0; i < n; i++) {
        printf(" %d  to %d : \t%d\n",start, i, dist[i]);
    }
}

int main() {
    int e, u, v, w, start;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter %d edges (u v w):\n", e);
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        // comment below if graph is undirected:
        adj[v][u] = w;
    }

    printf("Enter source vertex: ");
    scanf("%d", &start);

    dijkstra(start);

    return 0;
}
