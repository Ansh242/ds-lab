#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev; // Added previous pointer
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("mem allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void user(struct Node** head, int data) {
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
    newNode->prev = temp;
}

void insertFront(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    
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
    
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    
    printf("data %d deleted.\n", temp->data);
    free(temp);
}

void traverse(struct Node* head) {
    if (head == NULL) {
        printf("empty.\n");
        return;
    }
    struct Node* current = head;
    printf("current list: NULL <-> ");
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, value, numElements, i;
    printf("number of elements: ");
    scanf("%d", &numElements);

    for (i = 0; i < numElements; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        user(&head, value);
    }
    
    while (1) {
        printf("\n1. Insert at Front\n");
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
                while(head != NULL) {
                    deleteFront(&head);
                }
                exit(0);
            default:
                printf("try again.\n");
        }
    }

    return 0;
}