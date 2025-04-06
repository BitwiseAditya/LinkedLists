#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to find the middle of the linked list using the Tortoise and Hare algorithm
struct Node* findMiddle(struct Node* head) {
    struct Node* tortoise = head;
    struct Node* hare = head;

    // Traverse the linked list using the Tortoise and Hare algorithm
    while (hare != NULL && hare->next != NULL) {
        tortoise = tortoise->next;
        hare = hare->next->next;
    }

    // The tortoise now points to the middle of the linked list
    return tortoise;
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Insert values into the linked list
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    printf("Original Linked List: ");
    printList(head);

    // Find the middle of the linked list
    struct Node* middle = findMiddle(head);

    printf("Middle of the Linked List: %d\n", middle->data);

    return 0;
}
