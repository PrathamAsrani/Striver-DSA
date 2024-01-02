#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct queue
{
    int size, front, rear, *arr;
};

struct queue *createQueue(int s){
    struct queue *newQueue = (struct queue*) malloc (sizeof(struct queue));
    newQueue->front = newQueue->rear = -1;
    newQueue->size = s;
    newQueue->arr = (int*)malloc(sizeof(int));
    return newQueue;
}

void enQueue(struct queue *q, int data);
bool isFull(struct queue q);
bool isEmpty(struct queue q);
void display(struct queue q);
int deQueue(struct queue *q);

int main(){
    struct queue *q = createQueue(3);
    enQueue(q, 1);
    display(*q);
    enQueue(q, 1);
    display(*q);
    enQueue(q, 1);
    printf("Deleted: %d\n", deQueue(q));
    printf("Deleted: %d\n", deQueue(q));
    printf("Deleted: %d\n", deQueue(q));
    display(*q);
}

void enQueue(struct queue *q, int data){
    if(isFull(*q)){
        printf("Queue OverFlow\n");
    }else{
        if(q->front == -1){
            q->front = 0;
        }
        q->rear++;
        q->arr[q->rear] = data;
    }
}

bool isFull(struct queue q){
    if(q.rear == q.size-1) return true;
    return false;
}
bool isEmpty(struct queue q){
if(q.rear == -1) return true;
    return false;
}

void display(struct queue q){
    if(isEmpty(q)){
        printf("Queue underflow!\n");
    }else{
        for(int i = q.front; i < q.rear+1; i++){
            printf("%d ", q.arr[i]);
        }
        printf("\n");
    }
}

int deQueue(struct queue *q){
    if(isEmpty(*q)){
        printf("Queue is empty");
    }else{
        if(q->front == 0 && q->rear == 0){
            q->front = q->rear = -1;
            return q->arr[0];
        }else{
            int delItem = q->arr[q->front];
            q->front++;
            return delItem;
        }
    }
    return -1;
}