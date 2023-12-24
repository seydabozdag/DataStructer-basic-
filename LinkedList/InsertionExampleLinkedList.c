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

// Başa ekleme
struct Node* insertAtFirst(struct Node *head, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

// Araya ekleme
struct Node* insertAtIndex(struct Node *head, int data, int index) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head;
    int i = 0;
    while(i != index) {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

// Sona ekleme
struct Node* insertAtEnd(struct Node *head, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node* p = head;

    while(p->next != NULL) {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
} 

// Düğümden sonra ekleme
struct Node* insertAfterNode(struct Node *head, struct Node *prevNode, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
}

int main() {
    
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;
    // dynamic memory allocation
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

    printf("Linked List before insertion : \n");
    linkedListTraversal(head);
    head = insertAtFirst(head, 56);
    head = insertAtIndex(head, 50, 2);
    head = insertAtEnd(head, 56);
    head = insertAfterNode(head, third, 45);
    printf("\nLinked List after insertion : \n");
    linkedListTraversal(head);

    return 0;
}