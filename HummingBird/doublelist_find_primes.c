/* Find prime numbers in a double linked list */
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

// Function to check if a number is prime
int isPrime(int n) {
    if (n <= 1)
        return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

// Function to search for prime numbers in the linked list
void findPrimes(struct Node* head) {
    struct Node* current = head;

    printf("Prime numbers in the list: ");
    while (current != NULL) {
        if (isPrime(current->data))
            printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
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

    int values[10] = {6, 7, 8, 13, 15, 17, 23, 29, 143, 257};


    // Insert values into the doubly linked list using insertFirst
    for (int i = 0; i < 10; i++) {
        insertFirst(&head, values[i]);
    }

    printf("Original list: ");
    printList(head);

    findPrimes(head);

    return 0;
}
