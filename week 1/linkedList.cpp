#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* prev;
    Node* next;
};

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(Node** head, int value) {
    Node* newNode = new Node();
    newNode->val = value;
    newNode->prev = nullptr;
    newNode->next = *head;

    if (*head != nullptr)
        (*head)->prev = newNode;

    *head = newNode;
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(Node** head, int value) {
    Node* newNode = new Node();
    newNode->val = value;
    newNode->next = nullptr;

    if (*head == nullptr) {
        newNode->prev = nullptr;
        *head = newNode;
        return;
    }

    Node* lastNode = *head;
    while (lastNode->next != nullptr)
        lastNode = lastNode->next;

    lastNode->next = newNode;
    newNode->prev = lastNode;
}

// Function to delete a node from the linked list
void deleteNode(Node** head, Node* delNode) {
    if (*head == nullptr || delNode == nullptr)
        return;

    if (*head == delNode)
        *head = delNode->next;

    if (delNode->next != nullptr)
        delNode->next->prev = delNode->prev;

    if (delNode->prev != nullptr)
        delNode->prev->next = delNode->next;

    delete delNode;
}

// Function to display the linked list
void displayList(Node* head) {
    Node* currentNode = head;

    while (currentNode != nullptr) {
        cout << currentNode->val << " ";
        currentNode = currentNode->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    // Inserting elements at the beginning
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);

    cout << "Linked list after inserting at the beginning: ";
    displayList(head);

    // Inserting elements at the end
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    cout << "Linked list after inserting at the end: ";
    displayList(head);

    // Deleting a node
    Node* nodeToDelete = head->next;
    deleteNode(&head, nodeToDelete);

    cout << "Linked list after deleting a node: ";
    displayList(head);

    return 0;
}