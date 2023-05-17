#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createLinkedList(int n) {
    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 1; i <= n; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        if (newNode == NULL) {
            printf("Failed to allocate memory.\n");
            exit(1);
        }
        
        newNode->data = i;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

void printLinkedList(Node* head) {
    Node* currentNode = head;

    printf("Values of the linked list: ");
    while (currentNode != NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

void freeLinkedList(Node* head) {
    Node* currentNode = head;
    while (currentNode != NULL) {
        Node* temp = currentNode;
        currentNode = currentNode->next;
        free(temp);
    }
}

int main() {
    int n;

    printf("n: ");
    scanf("%d", &n);

    Node* head = createLinkedList(n);

    printLinkedList(head);

    freeLinkedList(head);

    return 0;
}