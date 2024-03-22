#include <stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100

struct PriorityQueue {
    int heap[MAX_SIZE]; 
    int size;           
};   

// Swap
void swap(int* a, int* b) {

    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(struct PriorityQueue* pq, int i) {

    int largest = i;
    int right = 2 * i + 2;
    int left = 2 * i + 1;
    
    // Check if the right child is larger than the largest so far
    if (right < pq->size && pq->heap[right] > pq->heap[largest])
        largest = right; 

    // Check if the left child is larger than the root
    if (left < pq->size && pq->heap[left] > pq->heap[largest])
        largest = left;

    // If the largest not the root, swap the root with the largest
    if (largest != i) {
        swap(&pq->heap[i], &pq->heap[largest]);
        maxHeapify(pq, largest);
    }
}

void buildMaxHeap(struct PriorityQueue* pq) {

    for (int i = pq->size / 2 - 1; i >= 0; i--) {
        maxHeapify(pq, i);
    }
}

void enqueue(struct PriorityQueue* pq, int value) {

    if (pq->size == MAX_SIZE) {
        printf("Priority Queue is full. Can not enqueue.\n");
        return;
    }

    pq->heap[pq->size] = value;
    pq->size++;

    buildMaxHeap(pq);
}

int dequeue(struct PriorityQueue* pq) {

    if (pq->size == 0) {
        printf("Priority Queue is empty. Can not dequeue.\n");
        return -1;  
    }

    int maxElement = pq->heap[0];
    pq->heap[0] = pq->heap[pq->size - 1];
    pq->size--;

    maxHeapify(pq, 0);

    return maxElement;
}

void printPriorityQueue(struct PriorityQueue* pq) {

    printf("Priority Queue: ");
    for (int i = 0; i < pq->size; i++) {
        printf("%d ", pq->heap[i]);
    }
    printf("\n");
}

int main() {
    struct PriorityQueue pq = {{48, 34, 24, 30, 12, 35, 13, 18, 21, 20}, 10}; 
    printf("Initial ");
    printPriorityQueue(&pq);

    // Enqueue
    enqueue(&pq, 15);
    printf("After Enqueue (15): ");
    printPriorityQueue(&pq);

    // Dequeue
    int maxElement = dequeue(&pq);
    if (maxElement != -1) {
        printf("Dequeued Max Element: %d\n", maxElement);
        printPriorityQueue(&pq);
    }

    return 0;
}