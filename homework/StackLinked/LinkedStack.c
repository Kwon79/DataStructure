#include"LinkedStack.h"

LinkedStack * createLinkedStack() {
    LinkedStack* re = (LinkedStack*)malloc(sizeof(LinkedStack));
    re->head = NULL;
    re->size = 0;

    return re;
}

void destroyLinkedStack(LinkedStack* s) {
    Node* nPtr, * mPtr;
    for (nPtr = s->head;nPtr != NULL;nPtr = mPtr) {
        mPtr = nPtr->next;
        free(nPtr);
    }
    free(s);
}

void initLinkedStack(LinkedStack* s) {
    s->head = NULL;
    s->size = 0;
}

int fullLinkedStack(LinkedStack* s) {
    return 0;
}

int emptyLinkedStack(LinkedStack* s) {
    if (s->size == 0) {
        return 1;
    }
    return 0;
}

void pushLinkedStack(LinkedStack* s, stackElement item) {
    Node* temp = (Node*)malloc(sizeof(Node));
    strncpy_s(temp->data,SIZE,item, SIZE - 1);
    temp->data[SIZE - 1] = '\0';
    temp->next = s->head;
    s->head = temp;
    s->size++;
}

int popLinkedStack(LinkedStack* s) {
    if (!emptyLinkedStack(s)) {
        Node* tPtr = s->head;
        s->head = tPtr->next;
        free(tPtr);
        s->size--;
        return 1;

    }
    else {
        printf("Stack is empty");
        return 0;
    }
}

void peakStack(LinkedStack* s, stackElement item) {
    if (!emptyLinkedStack(s)) {
        strncpy_s(item,SIZE,s->head->data, SIZE - 1);
        item[SIZE - 1] = '\0';
    }
    else {
        item[0] = '\0';
    }
}
void printLinkedStack(LinkedStack* s) {
    printf("Stack:\n");
    printf("Size: %d\n", s->size);
    Node* temp = s->head;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}