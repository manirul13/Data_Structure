/* This program implement Circular Linked List
 * Functions include insertEnd, displayList, search and deleteNode
 * */
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = newNode; // Point to itself (circular)
    return newNode;
}

// Function to insert a node at the end of the circular linked list
void insertEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head;
}

// Function to delete a node with a specific value
void deleteNode(Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node *curr = *head, *prev = NULL;
    while (curr->data != key) {
        if (curr->next == *head) {
            printf("Element %d not found!\n", key);
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    // If the node to be deleted is the only node
    if (curr->next == curr) {
        free(curr);
        *head = NULL;
        return;
    }

    // If the node to be deleted is the head
    if (curr == *head) {
        prev = *head;
        while (prev->next != *head) {
            prev = prev->next;
        }
        *head = curr->next;
        prev->next = *head;
        free(curr);
        return;
    }

    // For all other cases
    prev->next = curr->next;
    free(curr);
}

// Function to display the circular linked list
void displayList(Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Function to search for an element in the list
int search(Node* head, int key) {
    if (head == NULL) {
        return 0;
    }

    Node* temp = head;
    do {
        if (temp->data == key) {
            return 1; // Element found
        }
        temp = temp->next;
    } while (temp != head);

    return 0; // Element not found
}

// Main function for demonstration
int main() {
    Node* head = NULL;

    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);

    printf("Circular Linked List: \n");
    displayList(head);

    printf("\nDeleting 20...\n");
    deleteNode(&head, 20);
    displayList(head);

    printf("\nSearching for 30: %s\n", search(head, 30) ? "Found" : "Not Found");
    printf("Searching for 50: %s\n", search(head, 50) ? "Found" : "Not Found");

    return 0;
}

