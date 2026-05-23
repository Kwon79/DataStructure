#include "calculator.h"
#include "ArrayStack.h"

int infixToPostfix(char* infix, char* postfix) {
	int j = 0;
	ArrayStack* opStack = createArrayStack(100, CHARACTER);

	for (int i = 0; infix[i] != '\0'; i++) {
		if (infix[i] >= '0' && infix[i] <= '9') {
			postfix[j] = infix[i];
			j++;
		}
		else if (infix[i] == '+' || infix[i] == '-' ||
			infix[i] == '*' || infix[i] == '/') {
			while (!emptyArrayStack(opStack)) {
				stackElement prevOp = peekArrayStack(opStack);

				if (precedence(infix[i]) <= precedence(prevOp.operator)) {
					postfix[j] = popArrayStack(opStack).operator;
					j++;
				}
				else {
					break;
				}
			}
			stackElement newOp;
			newOp.operator = infix[i];
			pushArrayStack(opStack, newOp);
		}
		else if (infix[i] == '(') {
			stackElement newOp;
			newOp.operator = infix[i];
			pushArrayStack(opStack, newOp);
		}
		else if (infix[i] == ')') {
			do
			{
				stackElement prevOp = popArrayStack(opStack);


				if (prevOp.operator == '(') {
					break;
				}
				else {
					postfix[j] = prevOp.operator;
					j++;
				}
			} while (1);
		}
	}
	while (!emptyArrayStack(opStack)) {
		postfix[j] = popArrayStack(opStack).operator;
		j++;
	}

	postfix[j] = '\0';

	
}

int evalPostfix(char* postfix) {
	ArrayStack* valueStack = createArrayStack(100, INTEGER);
	int i = 0;

	while (postfix[i] != '\0') {
		if (postfix[i] >= '0' && postfix[i] <= '9') {
			stackElement elem;
			elem.value = postfix[i] - '0';
			pushArrayStack(valueStack, elem);
		}
		else if (postfix[i] == '*') {
			stackElement result;
			int i1 = popArrayStack(valueStack).value;
			int i2 = popArrayStack(valueStack).value;
			result.value = i1 * i2;

			pushArrayStack(valueStack, result);
		}
		else if (postfix[i] == '/') {
			int i1 = popArrayStack(valueStack).value;
			int i2 = popArrayStack(valueStack).value;
			stackElement result;
			result.value = i2 / i1;
			pushArrayStack(valueStack,result);
		}
		else if (postfix[i] == '+') {
			int i1 = popArrayStack(valueStack).value;
			int i2 = popArrayStack(valueStack).value;
			stackElement result;
			result.value = i1 + i2;
			pushArrayStack(valueStack, result);
		}
		else if (postfix[i] == '-') {
			int i1 = popArrayStack(valueStack).value;
			int i2 = popArrayStack(valueStack).value;
			stackElement result;
			result.value = i2 - i1;
			pushArrayStack(valueStack,result);	
		}

		i++;
	}
	
	return popArrayStack(valueStack).value;
}

int precedence(char op) {
	switch (op)
	{
	case ')':
		return 3;
	case '*':
	case '/':
		return 2;
	case '+':
	case '-':
		return 1;
	case '(':
		return 0;
	default:
		return 0;
	}
}



