#include"ArrayQueue.h"

ArrayQueue* createArrayQueue(int size) {
    ArrayQueue* temp = (ArrayQueue*)malloc(sizeof(ArrayQueue));

    temp->rear = 0;
    temp->front = 0;
    temp->data = (queueElement*)malloc(sizeof(queueElement));
    temp->size = size;

    return temp;
}
void destoryArrayQueue(ArrayQueue* q) {
    free(q->data);
    free(q);
}
int emptyArrayQueue(ArrayQueue* q) {
    return q->rear = q->front;
}

int fullArrayQueue(ArrayQueue* q) {
    return (q->rear + 1) % q->size == q->front;
}

int enqueueArrayQueue(ArrayQueue* q, queueElement item) {
    if (fullArrayQueue(q)) {
        return 0;
    }
    else {
        q->data[q->rear] = item;
        q->rear = (q->rear + 1) % q->size;
    }
}

queueElement dequeueArrayQueue(ArrayQueue* q) {
    if (emptyArrayQueue(q)) {
        return 0;
    }
    else {
        queueElement temp = q->data[q->front];
        q->front = (q->front + 1) % q->size;

        return temp;
    }
}

void printQueue(ArrayQueue* q) {
    printf("Array Queue:\n");
    printf("Front: %d,Rear: %d", q->data[q->front], q->data[q->rear]);

    if (emptyArrayQueue(q)) {
        return;
    }

    int rear = q->rear;
    int front = q->front;

    while (front != rear) {
        printf("%d", q->data[front]);
        front = (front + 1) % q->size;
    }
    printf("\n");
}