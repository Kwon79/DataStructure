#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100

typedef char stackElement[SIZE];

typedef struct node {
    stackElement data;
    struct node* next;
}Node;

typedef struct linkedStack {
    Node* head;
    int size;
}LinkedStack;

extern LinkedStack* createLinkedStack();
extern void destroyLinkedStack(LinkedStack* s);
extern void initLinkedStack(LinkedStack* s);
extern int emptyLinkedStack(LinkedStack* s);
extern int fullLinkedStack(LinkedStack* s);
extern void pushLinkedStack(LinkedStack* s, stackElement item);
extern int popLinkedStack(LinkedStack* s);
extern void peekStack(LinkedStack* s,stackElement item);
extern void printLinkedStack(LinkedStack* s);