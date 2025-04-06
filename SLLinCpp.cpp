#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* insertAtBeg(Node* head) {
    Node* newNode = new Node();
    if (newNode == nullptr) {
        cout << "Memory not available." << endl;
    } else {
        cout << "Enter data you want to insert at the beginning node of the linked list: ";
        cin >> newNode->data;
        newNode->next = head;
        head = newNode;
    }
    return head;
}

Node* insertAtEnd(Node* head) {
    Node* newNode = new Node();
    if (newNode == nullptr) {
        cout << "Memory not available." << endl;
    } else if (head == nullptr) {
        cout << "Enter info: ";
        cin >> newNode->data;
        head = newNode;
        newNode->next = nullptr;
    } else {
        cout << "Enter data you want to insert at the end node of the linked list: ";
        cin >> newNode->data;
        newNode->next = nullptr;
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}

Node* insertAfterSpecific(Node* head) {
    Node* newNode = new Node();
    int pos, i = 1;
    if (newNode == nullptr) {
        cout << "Memory not available." << endl;
    } else if (head == nullptr) {
        cout << "Enter info: ";
        cin >> newNode->data;
        head = newNode;
        newNode->next = nullptr;
    } else {
        cout << "Enter data you want to insert: ";
        cin >> newNode->data;
        newNode->next = nullptr;
        cout << "Enter position after which you want to insert: ";
        cin >> pos;
        Node* temp = head;
        while (i < pos) {
            temp = temp->next;
            i++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}

Node* deleteFromBeg(Node* head) {
    if (head == nullptr) {
        cout << "Linked list is empty." << endl;
    } else {
        cout << "Deleted element is: " << head->data << endl;
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    return head;
}

Node* deleteFromLast(Node* head) {
    if (head == nullptr) {
        cout << "Linked list is empty." << endl;
    } else {
        Node* temp = head;
        Node* prev = nullptr;
        while (temp->next != nullptr) {
            prev = temp;
            temp = temp->next;
        }
        cout << "Deleted element is: " << temp->data << endl;
        if (prev != nullptr) {
            prev->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
    }
    return head;
}

Node* deleteFromSpecific(Node* head) {
    int pos, i = 1;
    if (head == nullptr) {
        cout << "Linked list is empty." << endl;
    } else {
        cout << "Enter position from where you want to delete: ";
        cin >> pos;
        Node* temp = head;
        Node* prev = nullptr;
        while (i < pos && temp != nullptr) {
            prev = temp;
            temp = temp->next;
            i++;
        }
        if (temp == nullptr) {
            cout << "Position out of range." << endl;
        } else {
            cout << "Deleted element is: " << temp->data << endl;
            if (prev != nullptr) {
                prev->next = temp->next;
            } else {
                head = temp->next;
            }
            delete temp;
        }
    }
    return head;
}

Node* reverse(Node* head) {
    if (head == nullptr) {
        cout << "Linked list is empty." << endl;
    } else {
        Node* prevNode = nullptr;
        Node* currNode = head;
        Node* nextNode = nullptr;
        while (currNode != nullptr) {
            nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        head = prevNode;
    }
    return head;
}

Node* removeDup(Node* head) {
    Node* p1 = head;
    while (p1 != nullptr && p1->next != nullptr) {
        Node* p2 = p1;
        while (p2->next != nullptr) {
            if (p1->data == p2->next->data) {
                Node* p3 = p2->next;
                p2->next = p2->next->next;
                delete p3;
            } else {
                p2 = p2->next;
            }
        }
        p1 = p1->next;
    }
    return head;
}

void display(Node* head) {
    Node* temp = head;
    int count = 0;
    cout << "Linked list after operations:\n";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
        count++;
    }
    cout << endl;
    cout << "Total number of nodes: " << count << endl;
}

int main() {
    Node* head = nullptr;
    Node* temp;
    int choice = 1, choice2 = 1;

    while (choice) {
        Node* newNode = new Node();
        cout << "Enter data: ";
        cin >> newNode->data;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
        cout << "Do you want to continue (0,1): ";
        cin >> choice;
    }

    while (choice2) {
        cout << "Enter one to insert a new node at the beginning of the above-created linked list,\n"
             << "two to insert a new node at the end of the above-created linked list,\n"
             << "three to insert after a specified position,\n"
             << "four to delete a node from the beginning of the linked list,\n"
             << "five to delete from last,\n"
             << "six to delete from a specific position,\n"
             << "seven to reverse the linked list,\n"
             << "eight to remove duplicate elements from the linked list,\n"
             << "nine to display the so-formed linked list: ";
        int choice1;
        cin >> choice1;
        switch (choice1) {
            case 1:
                head = insertAtBeg(head);
                break;
            case 2:
                head = insertAtEnd(head);
                break;
            case 3:
                head = insertAfterSpecific(head);
                break;
            case 4:
                head = deleteFromBeg(head);
                break;
            case 5:
                head = deleteFromLast(head);
                break;
            case 6:
                head = deleteFromSpecific(head);
                break;
            case 7:
                head = reverse(head);
                break;
            case 8:
                head = removeDup(head);
                break;
            case 9:
                display(head);
                break;
            default:
                cout << "Invalid choice." << endl;
        }
        cout << "Do you want to continue to perform operations on the linked list? (0,1): ";
        cin >> choice2;
    }
    return 0;
}

