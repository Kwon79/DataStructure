#include"ArrayQueue.h"

int main() {
	ArrayQueue* myQueue = createArrayQueue(10);

	enqueueArrayQueue(myQueue, 1);
	enqueueArrayQueue(myQueue, 2);
	enqueueArrayQueue(myQueue, 3);
	enqueueArrayQueue(myQueue, 4);
	enqueueArrayQueue(myQueue, 5);

	printQueue(myQueue);

	dequeueArrayQueue(myQueue);

	printQueue(myQueue);

	dequeueArrayQueue(myQueue);

	printQueue(myQueue);

	dequeueArrayQueue(myQueue);

	printQueue(myQueue);

	return 0;
}