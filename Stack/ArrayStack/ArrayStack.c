#include"ArratStack.h"

ArrayStack* createArrayStack(int size) {
	ArrayStack* re = (ArrayStack*)malloc(sizeof(ArrayStack));
	re->data = (stackElement*)malloc(sizeof(stackElement));
	re->top = -1;
	
	return re;
}

int pushArrayStack(ArrayStack* s, stackElement item)
{

}