#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int* array;     
    int capacity;   
    int size;       
} Heap;

// Create new heap 
Heap* createHeap(int capacity) {

    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap->array = (int*)malloc(capacity * sizeof(int));
    heap->capacity = capacity;
    heap->size = 0;
    return heap;
}

// Swap
void swap(int* a, int* b) {

    int temp = *a;
    *a = *b;
    *b = temp;
}


void heapify(Heap* heap, int i) {

    int largest = i;
    int right = 2 * i + 2;
    int left = 2 * i + 1;
    
    // Check if the right child is larger than the largest so far
    if (right < heap->size && heap->array[right] > heap->array[largest])
        largest = right; 

    // Check if the left child is larger than the root
    if (left < heap->size && heap->array[left] > heap->array[largest])
        largest = left;

    // If the largest not the root, swap the root with the largest
    if (largest != i) {
        swap(&heap->array[i], &heap->array[largest]);
        heapify(heap, largest);
    }
}

// Insert
void insert(Heap* heap, int value) {

    if (heap->size == heap->capacity) {
        printf("Heap is full. Can not insert more elements.\n");
        return;
    }

    // Insert new element at the end
    int i = heap->size++;
    heap->array[i] = value;

    while (i != 0 && heap->array[(i - 1) / 2] < heap->array[i]) {
        swap(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Delete Max heap
int deleteMax(Heap* heap) {

    if (heap->size == 0) {
        printf("Heap is empty. Can not remove maximum element.\n");
        return -1;
    }

    int max = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;

    // Heapify root
    heapify(heap, 0);
    return max;
}

// Print elements of the heap
void printHeap(Heap* heap) {

    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->array[i]);
    }
    printf("\n");
}

void destroyHeap(Heap* heap) {

    free(heap->array);
    free(heap);
}

// Usage of the heap
int main() {

    Heap* heap = createHeap(10);
    insert(heap, 48);
    insert(heap, 34);
    insert(heap, 35);
    insert(heap, 6);
    insert(heap, 15);
    insert(heap, 18);
    insert(heap, 30);
    insert(heap, 96);
    insert(heap, 72);
    insert(heap, 1);

    printf("Heap elements before deletion: ");
    printHeap(heap);
    int max = deleteMax(heap);
    printf("Maximum element: %d\n", max);
	printf("Heap elements after deletion: ");
    printHeap(heap);
    destroyHeap(heap);
    return 0;
}
