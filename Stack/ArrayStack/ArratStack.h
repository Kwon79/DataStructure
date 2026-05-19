#include<stdio.h>
#include<stdlib.h>

typedef int stackElement;

typedef struct arrayStack {
	stackElement* data;
	int top;
	int size;
}ArrayStack;

extern ArrayStack* createArrayStack(int size);
extern int destroyArrayStack(ArrayStack* s); //나 스스로 구현하기
//initArrayStack 필요하면 선언 및 구현하기
extern int pushArrayStack(ArrayStack* s, stackElement item);
extern stackElement popArrayStack(ArrayStack* s);
extern emptyArrayStack(ArrayStack* s);
extern fullArrayStack(ArrayStack* s);
//peekArrayStac 알아서 선언 및 구현하기