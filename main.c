#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <queue>

#define MAX_V 10000
#define MAX_E 100000

int V, E; // number of vertices and edges
int adj[MAX_V][MAX_V]; // adjacency matrix
bool visited[MAX_V]; // visited array
int distance[MAX_V]; // distance array

void bfs(int s) {
    // initialize visited and distance arrays
    for (int i = 1; i <= V; i++) {
        visited[i] = false;
        distance[i] = -1; // set distance to -1 
    }
    // start BFS from source vertex s
    visited[s] = true;
    distance[s] = 0;
    int queue[MAX_V], front = 0, rear = -1;
    queue[++rear] = s;
    while (front <= rear) {
        int u = queue[front++];
        for (int v = 1; v <= V; v++) {
            if (adj[u][v] ==1 && !visited[v]) {
                visited[v] = true;
                distance[v] = distance[u] + 1;
                queue[++rear] = v;
            }
        }
    }
}

int main() {
    scanf("%d %d", &V, &E);
    // adjacency matrix
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            adj[i][j] = 0;
        }
    }
    // read edges and build adjacency matrix
    for (int i = 1; i <= E; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        adj[x][y] = adj[y][x] = 1; // undirected graph, we intializing the values as 1 when there is an edge between 2 nodes
    }
    int s, d; // taking source and destination node
    scanf("%d %d", &s, &d);
    bfs(s); //applying bfs to calculate distance
    if (distance[d] == -1) {
        printf("INF\n");
    } else {
        printf("%d\n", distance[d]);
    }
    return 0;
}