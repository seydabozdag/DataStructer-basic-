#include<stdio.h>
 
 
void display(int arr[], int n) {

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");   
}


 // Insertion
int indInsertion(int arr[], int size, int element, int capacity, int index) {
    
    if(size >= capacity){
        return -1;
    }
    for (int i = size-1; i >= index; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[index] = element;
    return 1; 
}
 
// Büyükten küçüğe sıralama
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] < arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int arr[100] = {25, 15, 18, 30, 92};
    int size = 5, element = 48, index = 3;
    
    display(arr, size); 
    indInsertion(arr, size, element, 100, index);
    size += 1;
    display(arr, size);
    
    bubbleSort(arr, size);
    printf("Array'in buyukten kucuge siralanmis ve son hali :\n");
    display(arr, size);
    
    return 0;
}
