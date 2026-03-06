#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int front;
    int rear;
    int capacity;
    int* array;
};

// 1. Initialize the queue
struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

// 2. Check if the queue is full (rear has reached the end of the array)
int isFull(struct Queue* queue) {
    return (queue->rear == queue->capacity - 1);
}

// 3. Check if the queue is empty (front pointer has passed the rear pointer)
int isEmpty(struct Queue* queue) {
    return (queue->front > queue->rear);
}

// 4. Add an item to the back of the line
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full! 🛑 Cannot enqueue %d\n", item);
        return;
    }
    queue->rear++;
    queue->array[queue->rear] = item;
    printf("%d joined the line.\n", item);
}

// 5. Remove an item from the front of the line
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty! 🤷‍♂️ Nothing to dequeue.\n");
        return -1; // Returning -1 as an error code
    }
    int item = queue->array[queue->front];
    queue->front++;
    printf("%d left the line.\n", item);
    return item;
}

// 6. Test it out
int main() {
    // Create a queue that can hold 3 items
    struct Queue* myQueue = createQueue(3);

    enqueue(myQueue, 10);
    enqueue(myQueue, 20);
    enqueue(myQueue, 30);
    
    // Trying to add a 4th item will trigger our isFull check
    enqueue(myQueue, 40); 

    dequeue(myQueue);
    dequeue(myQueue);

    return 0;
}