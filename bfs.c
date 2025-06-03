#include<stdio.h>
#define m 100
int adj[m][m];
int visited[m];
int queue[m];
int front =0,rear=-1;

void enqueue(int v){
    if(rear==m-1) return ;
    queue[++rear]=v;
}
int dequeue(){
    if(front>rear) return -1;
     return queue[front++];
}
void bfs(int start,int v){
    for(int i=0;i<m;i++){
        visited[i]=0;
    }
    enqueue(start);
    visited[start]=1;
    
     printf("\nBFS Traversal starting from node %d: ", start);
    while( front <= rear){
         int current = dequeue();
        printf("%d ", current);

        for (int i = 0; i < v; i++) {
            if (adj[current][i] == 1 && visited[i]!=1) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    
    printf("\n");
}

int main(){
 
    int n,u,v,e,start;
    printf("enter verx and edges: ");
    scanf("%d %d",&n,&e);

    printf("enter adjacency list in (u,v) :\n");
    for(int i=0;i<e;i++){
     scanf("%d%d",&u,&v);
     adj[u][v]=1;
     adj[v][u]=1;
    }
    printf("enter start position:");
    scanf("%d",&start);
    bfs(start,n);
return 0;
}