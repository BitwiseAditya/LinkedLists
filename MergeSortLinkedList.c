#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to merge two sorted linked lists
struct Node* merge(struct Node* left, struct Node* right) {
    struct Node* result = NULL;

    // Base cases
    if (left == NULL) {
        return right;
    }
    if (right == NULL) {
        return left;
    }

    // Compare the data of the two nodes and merge them
    if (left->data <= right->data) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }

    return result;
}

// Function to perform Merge Sort on a linked list
void mergeSort(struct Node** head) {
    struct Node* current = *head;
    struct Node* left;
    struct Node* right;

    // Base case: If the list is empty or has only one node, it is already sorted
    if (current == NULL || current->next == NULL) {
        return;
    }

    // Split the list into two halves
    struct Node* slow = current;
    struct Node* fast = current->next;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }

    left = current;
    right = slow->next;
    slow->next = NULL;

    // Recursively sort the two halves
    mergeSort(&left);
    mergeSort(&right);

    // Merge the sorted halves
    *head = merge(left, right);
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
    insertAtEnd(&head, 12);
    insertAtEnd(&head, 11);
    insertAtEnd(&head, 13);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 6);

    printf("Original Linked List: ");
    printList(head);

    // Perform Merge Sort on the linked list
    mergeSort(&head);

    printf("Sorted Linked List: ");
    printList(head);

    return 0;
}
