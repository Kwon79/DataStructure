#include"DLinkedList.h"

DLinkedList* createDLinkedLiest() {
	DLinkedList* temp;
	temp = (DLinkedList*)malloc(sizeof(DLinkedList));
	temp->head.prev = &temp->head;
}
void destrotyDLinkedList(DLinkedList* dl) {
	while (dl->size != 0) {
		deleteFristLinkedList(dl);
	}
	free(dl);
}
int insertFirstDLinkedList(DLinkedList* dl, PointType item) {
	PointType* nPtr = (PointType*)malloc(sizeof(PointType));
	*nPtr = item;

	nPtr->prev = &(dl->head);
	nPtr->next = dl->head.next;
	dl->head.next = nPtr;
	nPtr->next->prev = nPtr;

	dl->size++;
}
int insertLastDLinkedList(DLinkedList* dl, PointType item) {
	PointType* nPtr = (PointType*)malloc(sizeof(PointType));
	*nPtr = item;

	nPtr->prev = dl->head.prev;
	nPtr->next = &(dl->head);
	nPtr->prev->next = nPtr;
	nPtr->next->prev=nPtr;
	dl->size++;
}
PointType deleteFirstDLinkedList(DLinkedList* dl) {
	PointType* temp = dl->head.next;
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;

	dl->size--;
	free(temp);
}
void  printDLinkedList(DLinkedList* dl) {

	if (dl->size == -0) {
		return;
	}

}