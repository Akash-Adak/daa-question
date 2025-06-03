#include <stdio.h>
#define MAX 100

int mat[MAX][MAX];
int color[MAX];

void graphColoring(int v) {
    for (int u = 0; u < v; u++) {
        int used[MAX] = {0};

        // Mark colors used by adjacent vertices
        for (int adj = 0; adj < v; adj++) {
            if (mat[u][adj] && color[adj] != 0) {
                used[color[adj]] = 1;
            }
        }

        // Find the smallest color not used
        for (int c = 1; c <= v; c++) {
            if (!used[c]) {
                color[u] = c;
                break;
            }
        }
    }
}

int main() {
    int v;
    printf("Enter number of vertices: ");
    scanf("%d", &v);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    graphColoring(v);

    printf("Assigned Colors (1-based):\n");
    for (int i = 0; i < v; i++) {
        printf("Vertex %d -> Color %d\n", i, color[i]);
    }

    return 0;
}
