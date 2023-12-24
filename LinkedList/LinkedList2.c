#include<stdio.h>
#include<stdlib.h>

// Node Yapısı
struct Node {
    int data;
    struct Node* next;

};

// Linked List'i yazdıran fonksiyon
void printLinkedList(struct Node* head) {
    while(head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    // İlk node'u oluşturalım ve bu node'a başlangıç (head->data) değerini atayalım

    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1;
    head->next = NULL;

    // Diğer node'ları oluşturup Linked List'e ekleyelim
    struct Node* current = head;
    for(int i=2; i<=5; i++) {
        current->next = (struct Node*)malloc(sizeof(struct Node));
        current = current->next;
        current->data = i;
        current->next = NULL;
    }

    // Oluşturulan Linked List'i yazdıralım
    printf("Linked List: ");
    printLinkedList(head);

    // Belleği serbest bırakalım
    current = head;
    while (head != NULL) {
        head = head->next;
        free(current);
        current = head;
    }

    return 0;

}