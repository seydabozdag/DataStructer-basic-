#include<stdio.h>
#include<stdlib.h>

int linearSearch(int arr[], int size, int element) {
    for(int i = 0; i< size; i++) {
        if(arr[i] == element) {
            return i;
        }
    }
    return -1;
}

int binarySearch (int arr[], int size, int element) {
    int low, mid, high;
    low = 0;
    high = (size-1);
    // Start searching
        while(low<=high) {
            mid = (low + high)/2;
        if(arr[mid] == element) {
            return mid;
        }
        if(arr[mid]<element) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }

        }
        
    return -1;
}


int main() {
    // Unsorted array for linear search 
    int arr_linear[] = {1,3,5,56,4,3,23,5,4,546,56,34};
    int size_linear = sizeof(arr_linear) / sizeof(int);
    int element_linear = 56;
    int searchIndex_linear = linearSearch(arr_linear, size_linear, element_linear);
    if(searchIndex_linear != -1) {
        printf("The element %d found at index %d with linear search\n", element_linear, searchIndex_linear);
    }
    else {
        printf("The element %d is not found\n", element_linear);
    }


    // Sorted array for binary search
    int arr_binary[] = {1,3,5,56,64,73,83,95,104,246,256,334};
    int size_binary = sizeof(arr_binary)/sizeof(int);
    int element_binary = 104;
    int searchIndex_binary = binarySearch(arr_binary, size_binary, element_binary);
    if(searchIndex_binary != -1) {
        printf("The element %d found at index %d with binary search\n", element_binary, searchIndex_binary);
    }
    else {
        printf("The element %d is not found\n", element_binary);
    }

    return 0;
}