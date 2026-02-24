#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertFront(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
    printf("data %d inserted.\n", data);
}
void deleteFront(struct Node** head) {
    if (*head == NULL) {
        printf("empty.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    printf("data %d deleted.\n", temp->data);
    free(temp);
}
void traverse(struct Node* head) {
    if (head == NULL) {
        printf("empty.\n");
        return;
    }
    struct Node* current = head;
    printf("current list: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, value;

    while (1) {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert at Front\n");
        printf("2. Delete from Front\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertFront(&head, value);
                break;
            case 2:
                deleteFront(&head);
                break;
            case 3:
                traverse(head);
                break;
            case 4:
                printf("Exit\n");
                while(head != NULL) deleteFront(&head);
                exit(0);
            default:
                printf("try again.\n");
        }
    }

    return 0;
}