#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void linkedListTraversal(struct Node* ptr) {
    while (ptr != NULL) {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node* insertAtFirst(struct Node* head, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

struct Node* insertAtIndex(struct Node* head, int data, int index) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head;
    int i = 0;
    while (i != index - 1) {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node* p = head;

    while (p->next != NULL) {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

struct Node* insertAfterNode(struct Node* head, struct Node* prevNode, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}

int main() {

    // Sample nodes
    struct Node* head;
    struct Node* second = NULL;
    struct Node* third = NULL;
    struct Node* fourth = NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));
    
    // Linked first and second nodes
    head->data = 7;
    head->next = second;

    // Link second and third nodes
    second->data = 8;
    second->next = third;

    // Link third and fourth nodes
    third->data = 11;
    third->next = fourth;
 
    // Fourth node
    fourth->data = 66;
    fourth->next = NULL;

    int choice, data, index;
    printf("Linked List before insertion : \n");
    linkedListTraversal(head);
    
    do {
        printf("\n1. Insert at the beginning\n");
        printf("2. Insert at a specific index\n");
        printf("3. Insert at the end\n");
        printf("4. Insert after a node\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                head = insertAtFirst(head, data);
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter index to insert at: ");
                scanf("%d", &index);
                head = insertAtIndex(head, data, index);
                break;
            case 3:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 4:
                printf("Enter data to insert after a node: ");
                scanf("%d", &data);
                printf("Enter the data of the node after which to insert: ");
                scanf("%d", &index);
                struct Node* temp = head;
                while (temp->data != index) {
                    temp = temp->next;
                }
                head = insertAfterNode(head, temp, data);
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

        printf("\nLinked List after insertion : \n");
        linkedListTraversal(head);

    } while(choice != 0);

    return 0;
}