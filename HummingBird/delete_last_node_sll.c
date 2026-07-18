/* Program to delete last node from SLL */
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the end of the list
void appendNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
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

// Function to remove the last node of the linked list
void removeLastNode(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    // If there's only one node
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    // Traverse to the second last node
    struct Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    // Free the last node and set the second last node's next to NULL
    free(temp->next);
    temp->next = NULL;
}

// Function to display the linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Add nodes to the list
    appendNode(&head, 10);
    appendNode(&head, 20);
    appendNode(&head, 30);
    appendNode(&head, 40);

    printf("Original List:\n");
    displayList(head);

    // Remove the last node
    printf("Removing the last node...\n");
    removeLastNode(&head);

    printf("Updated List:\n");
    displayList(head);

    return 0;
}

