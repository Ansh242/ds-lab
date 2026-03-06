#include <stdio.h>
#include<stdlib.h>

struct queue
{
    int capacity;
    int rear;
    int front;
    int *array;
};

struct queue *createqueue(int capacity)
{
    struct queue *Queue=(struct queue*)malloc(sizeof(struct queue));
    Queue->capacity=capacity;
    Queue->front=0;
    Queue->rear=-1;
    Queue->array=(int*)malloc(Queue->capacity*sizeof(int));
    return Queue;    
};

int isFull(struct queue *Queue){
    return (Queue->rear==Queue->capacity-1);
}

int isEmpty(struct queue *Queue){
    return(Queue->rear==Queue->front);
}

void enqueue(struct queue *Queue,int item){
    if (isFull(Queue)){
        printf("no space\n");
        return;
    }
    Queue->rear++;
    Queue->array[Queue->rear]=item;
    printf("added\n");
}

int dequeue(struct queue *Queue){
    if(isEmpty(Queue)){
        printf("nothing to remove\n");
        return -1;
    }
    int item=Queue->array[Queue->front];
    Queue->front++;
    printf("removed\n");
    return item;
}

int main(void){
    struct queue *Q=createqueue(3);

    enqueue(Q,10);
    enqueue(Q,956);
    enqueue(Q,95);
    enqueue(Q, 40); 

    dequeue(Q);
    dequeue(Q);

    return 0;
}