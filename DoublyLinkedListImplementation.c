#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (position <= 0) {
        printf("Invalid position.\n");
        return;
    }
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        for (int i = 1; i < position - 1 && temp != NULL; ++i) {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Invalid position.\n");
        } else {
            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next != NULL) {
                temp->next->prev = newNode;
            }
            temp->next = newNode;
        }
    }
}

void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
    } else {
        struct Node* temp = *head;
        *head = (*head)->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
    }
}

void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        if (temp->prev != NULL) {
            temp->prev->next = NULL;
        } else {
            *head = NULL;
        }
        free(temp);
    }
}

void deleteFromPosition(struct Node** head, int position) {
    if (*head == NULL || position <= 0) {
        printf("Invalid position or empty list.\n");
        return;
    }
    struct Node* temp = *head;
    for (int i = 1; i < position && temp != NULL; ++i) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position.\n");
    } else {
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        } else {
            *head = temp->next;
        }
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
        free(temp);
    }
}

void removeDuplicates(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current->next;
        while (temp != NULL && temp->data == current->data) {
            struct Node* duplicate = temp;
            temp = temp->next;
            if (duplicate->prev != NULL) {
                duplicate->prev->next = temp;
            }
            if (temp != NULL) {
                temp->prev = duplicate->prev;
            }
            free(duplicate);
        }
        current = current->next;
    }
}

void reverseList(struct Node** head) {
    struct Node* temp = NULL;
    struct Node* current = *head;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL) {
        *head = temp->prev;
    }
}

void displayList(struct Node* head) {
    printf("Doubly Linked List: ");
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 3);
    insertAtEnd(&head, 7);
    insertAtEnd(&head, 7);
    insertAtEnd(&head, 9);
    insertAtPosition(&head, 12, 4);

    displayList(head);

    removeDuplicates(head);
    printf("After removing duplicates: ");
    displayList(head);

    deleteFromBeginning(&head);
    printf("After deleting from the beginning: ");
    displayList(head);

    deleteFromEnd(&head);
    printf("After deleting from the end: ");
    displayList(head);

    deleteFromPosition(&head, 2);
    printf("After deleting from position 2: ");
    displayList(head);

    reverseList(&head);
    printf("Reversed List: ");
    displayList(head);

    // You can perform more operations here

    return 0;
}
