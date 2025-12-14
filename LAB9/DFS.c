#include <stdio.h>
#define MAX 20

int stack[MAX], top = -1;
int visited[MAX];

void push(int v) {
    stack[++top] = v;
}

int pop() {
    if (top == -1) return -1;
    return stack[top--];
}

void DFS_Stack(int adj[MAX][MAX], int n, int start) {
    int i, v;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    push(start);

    while (top != -1) {
        v = pop();

        if (!visited[v]) {
            visited[v] = 1;
        }

        for (i = n - 1; i >= 0; i--) {
            if (adj[v][i] == 1 && !visited[i]) {
                push(i);
            }
        }
    }
}

int main() {
    int n, adj[MAX][MAX];
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    DFS_Stack(adj, n, 0);

    int connected = 1;
    for (i = 0; i < n; i++) {
        if (!visited[i]) {
            connected = 0;
            break;
        }
    }

    if (connected)
        printf("Graph is Connected\n");
    else
        printf("Graph is NOT Connected\n");

    return 0;
}
