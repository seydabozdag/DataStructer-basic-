#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void linkedListTraversal(struct Node* ptr) {
    while(ptr != NULL) {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Case1: Deleting the first element from the linked list
struct Node* deleteFirst(struct Node* head) {
    struct Node* ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// Case2: Deleting the element a given index from the linked list
struct Node* deleteAtIndex(struct Node* head, int index) {
    struct Node *p = head;
    struct Node *q = head->next;
    for(int i = 0; i < index-1; i++) {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q); 
    return head;
}

// Case3: Deleting the last element from the linked list
struct Node* deleteAtLast(struct Node* head) {
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->next != NULL) {
      p = p->next;
      q = q->next;  
    }

    p->next = NULL;
    free(q); 
    return head;
}

// Case4: Deleting the element with a given value from the linked list
struct Node* deleteAtValue(struct Node* head, int value) {
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->data != value && q->next != NULL) {
        p = p->next;
        q = q->next;
    }

    if(q->data == value) {
        p->next = q->next;
        free(q);
    }
    return head;
}

int main() {
    
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;

    // Dynamic memory allocation
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));

    // Linked first and second nodes
    head->data = 4;
    head->next = second;

    // Link second and third nodes
    second->data = 3;
    second->next = third;

    // Link third and fourth nodes
    third->data = 8;
    third->next = fourth;

    // Fourth node
    fourth->data = 1;
    fourth->next = NULL;

    int choice, data, index, value;
    printf("Linked list before deletion\n");
    linkedListTraversal(head);

    do {
        printf("\n1. Delete at the beginning\n");
        printf("2. Delete at a specific index\n");
        printf("3. Delete at the end\n");
        printf("4. Delete at a given value\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to delete at the beginning: ");
                scanf("%d", &data);
                head = deleteFirst(head); // For deleting first element of the linked list
                break;
            case 2:
                printf("Enter index to delete at: ");
                scanf("%d", &index);
                head = deleteAtIndex(head, index); // For deleting the element given index
                break;
            case 3:
                printf("Enter data to delete at the end: ");
                scanf("%d", &data);
                head = deleteAtLast(head); // For deleting the last element
                break;
            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                head = deleteAtValue(head, value); // For deleting the given value
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        } 

        printf("Linked list after deletion\n");
        linkedListTraversal(head);

    } while(choice != 0);
    
    return 0;

}