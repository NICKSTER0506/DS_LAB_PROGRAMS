#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// Insert to the left of a node with given value
void insertLeft(struct Node** head, int target, int data) {
    struct Node* temp = *head;
    while (temp && temp->data != target) temp = temp->next;
    if (!temp) {
        printf("Target %d not found!\n", target);
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = temp;
    newNode->prev = temp->prev;
    if (temp->prev) temp->prev->next = newNode;
    else *head = newNode; // inserting before head
    temp->prev = newNode;
}

// Delete node by value
void deleteNode(struct Node** head, int target) {
    struct Node* temp = *head;
    while (temp && temp->data != target) temp = temp->next;
    if (!temp) {
        printf("Node %d not found!\n", target);
        return;
    }
    if (temp->prev) temp->prev->next = temp->next;
    else *head = temp->next; // deleting head
    if (temp->next) temp->next->prev = temp->prev;
    free(temp);
    printf("Node %d deleted.\n", target);
}

// Display list
void display(struct Node* head) {
    struct Node* temp = head;
    if (!head) {
        printf("List is empty.\n");
        return;
    }
    printf("List: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, target;

    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at End\n");
        printf("2. Insert to the Left of a Node\n");
        printf("3. Delete a Node\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertEnd(&head, data);
                break;
            case 2:
                printf("Enter target node value: ");
                scanf("%d", &target);
                printf("Enter data to insert left of %d: ", target);
                scanf("%d", &data);
                insertLeft(&head, target, data);
                break;
            case 3:
                printf("Enter node value to delete: ");
                scanf("%d", &target);
                deleteNode(&head, target);
                break;
            case 4:
                display(head);
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
