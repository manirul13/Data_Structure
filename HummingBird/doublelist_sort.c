/* Program to sort double linked list */
#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the double linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

// Function to insert a node at the beginning of the list
void insertFirst(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

// Function to sort the doubly linked list
void sortList(struct Node** head) {
    struct Node *current, *index;
    int temp;

    // Check if the list is empty or has only one node
    if (*head == NULL || (*head)->next == NULL)
        return;

    // Traverse the list with two pointers
    current = *head;
    while (current->next != NULL) {
        // Start comparing from the next node of current
        index = current->next;
        while (index != NULL) {
            // If current node's data is greater than index node's data, swap the data
            if (current->data > index->data) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
        // Move to the next node
        current = current->next;
    }
}


// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Node* head = NULL;

    // Initialize an integer array of size 10 with mixed prime and non-prime values
    int values[10] = {29, 6, 17, 100, 7, 15, 23, 200, 8, 13};

    // Insert values into the doubly linked list using insertFirst
    for (int i = 0; i < 10; i++) {
        insertFirst(&head, values[i]);
    }

    printf("Original list: ");
    printList(head);

    // Sort the doubly linked list
    sortList(&head);

    printf("Sorted list: ");
    printList(head);


    return 0;
}
