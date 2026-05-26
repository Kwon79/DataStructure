#include<stdio.h>
#include<stdlib.h>

typedef int queueElement;

typedef struct arrayQueue {
    int rear;
    int front;
    int size;

    queueElement* data;
}ArrayQueue;

extern ArrayQueue* createArrayQueue(int size);
extern void destoryArrayQueue(ArrayQueue* q);
extern int emptyArrayQueue(ArrayQueue* q);
extern int fullArrayQueue(ArrayQueue* q);
extern int enqueueArrayQueue(ArrayQueue* q, queueElement item);
extern queueElement dequeueArrayQueue(ArrayQueue* q);
extern void printQueue(ArrayQueue* q);