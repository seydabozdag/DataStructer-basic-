#include <stdio.h>
 
void display(int arr[], int n) {

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Deletion
void indDeletion(int arr[], int size, int index) {
    for (int i = index; i < size-1; i++)
    {
        arr[i] = arr[i + 1];
    }  
}
 
int main() {
    int arr[100] = {25, 15, 18, 30, 92};
    int size = 5, index = 0;
    display(arr, size);
    indDeletion(arr, size, index);
    size -= 1;
    printf("Array'in son hali :\n");
    display(arr, size);
    return 0;
}
