#include<stdio.h>
#define v 5

void initGraph(int arr[][v]) {

    int i,j;
    for(i = 0; i < v; i++)
        for(j = 0; j < v; j++)
            arr[i][j] = 0;

}

void addEdge(int arr[][v],int start, int end) {

    arr[start][end] = 1;
    arr[end][start] = 1;

}

void printAdjMatrix(int arr[][v]) {

    int i, j;

    for(i = 0; i < v; i++) {
        for(j = 0; j < v; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {

    int adjMatrix[v][v];

    initGraph(adjMatrix);
    addEdge(adjMatrix,0,1);
    addEdge(adjMatrix,1,2);
    addEdge(adjMatrix,1,3);
    addEdge(adjMatrix,2,3);
    addEdge(adjMatrix,2,4);
    addEdge(adjMatrix,3,3);
    addEdge(adjMatrix,3,4);

    printAdjMatrix(adjMatrix);

    return 0;
}
