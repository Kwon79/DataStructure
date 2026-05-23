#include"ArrayStack.h"
#include "calculator.h"

char infix[100];
char postfix[100];

void input() {
	printf("입력:");
	fgets(infix, sizeof(infix), stdin);
	infix[strlen(infix) - 1] = '\0';
}

int main() {
	input();

	infixToPostfix(infix, postfix);

	evalPostfix(postfix);

	return 0;
}