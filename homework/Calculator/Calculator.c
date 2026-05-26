#include "calculator.h"
#include "ArrayStack.h"

int infixToPostfix(char* infix, char* postfix) {

    int j = 0;

    postfix[0] = '\0';

    ArrayStack* opStack = createArrayStack(100, CHARACTER);

    printf("Transform:\n");

    for (int i = 0; infix[i] != '\0'; i++) {

        if (infix[i] == ' ') {
            continue;
        }

        // 숫자
        if (infix[i] >= '0' && infix[i] <= '9') {

            postfix[j++] = infix[i];
            postfix[j++] = ' ';
            postfix[j] = '\0';

            printf("- Postfix: %s| Stack: ", postfix);

            for (int k = 0; k <= opStack->top; k++) {
                printf("%c ", opStack->data[k].operator);
            }

            printf("\n");
        }

        // 연산자
        else if (infix[i] == '+' || infix[i] == '-' ||
            infix[i] == '*' || infix[i] == '/') {

            while (!emptyArrayStack(opStack)) {

                stackElement prevOp = peekArrayStack(opStack);

                if (precedence(infix[i]) <= precedence(prevOp.operator)) {

                    postfix[j++] = popArrayStack(opStack).operator;
                    postfix[j++] = ' ';
                    postfix[j] = '\0';
                }
                else {
                    break;
                }
            }

            stackElement newOp;
            newOp.operator = infix[i];

            pushArrayStack(opStack, newOp);

            printf("- Postfix: %s| Stack: ", postfix);

            for (int k = 0; k <= opStack->top; k++) {
                printf("%c ", opStack->data[k].operator);
            }

            printf("\n");
        }

        // 여는 괄호
        else if (infix[i] == '(') {

            stackElement newOp;
            newOp.operator = infix[i];

            pushArrayStack(opStack, newOp);

            printf("- Postfix: %s| Stack: ", postfix);

            for (int k = 0; k <= opStack->top; k++) {
                printf("%c ", opStack->data[k].operator);
            }

            printf("\n");
        }

        // 닫는 괄호
        else if (infix[i] == ')') {

            while (!emptyArrayStack(opStack)) {

                stackElement prevOp = popArrayStack(opStack);

                if (prevOp.operator == '(') {
                    break;
                }

                postfix[j++] = prevOp.operator;
                postfix[j++] = ' ';
                postfix[j] = '\0';
            }

            printf("- Postfix: %s| Stack: ", postfix);

            for (int k = 0; k <= opStack->top; k++) {
                printf("%c ", opStack->data[k].operator);
            }

            printf("\n");
        }
    }

    // 남은 연산자 전부 pop
    while (!emptyArrayStack(opStack)) {

        postfix[j++] = popArrayStack(opStack).operator;
        postfix[j++] = ' ';
        postfix[j] = '\0';
    }

    printf("- Postfix: %s| Stack: ", postfix);

    for (int k = 0; k <= opStack->top; k++) {
        printf("%c ", opStack->data[k].operator);
    }

    printf("\n");

    printf("\n- Result: %s\n\n", postfix);

    destroyArrayStack(opStack);

    return 1;
}

int evalPostfix(char* postfix) {

    ArrayStack* valueStack = createArrayStack(100, INTEGER);

    int i = 0;

    printf("Eval:\n");
    printf("- Postfix: %s\n", postfix);

    while (postfix[i] != '\0') {

        if (postfix[i] == ' ') {
            i++;
            continue;
        }

        
        if (postfix[i] >= '0' && postfix[i] <= '9') {

            stackElement elem;

            elem.value = postfix[i] - '0';

            pushArrayStack(valueStack, elem);

            printf("- Current: %c | Stack: ", postfix[i]);

            for (int k = 0; k <= valueStack->top; k++) {
                printf("%d ", valueStack->data[k].value);
            }

            printf("\n");
        }

        
        else if (postfix[i] == '*') {

            int i1 = popArrayStack(valueStack).value;
            int i2 = popArrayStack(valueStack).value;

            stackElement result;

            result.value = i2 * i1;

            pushArrayStack(valueStack, result);

            printf("- Current: %c | Stack: ", postfix[i]);

            for (int k = 0; k <= valueStack->top; k++) {
                printf("%d ", valueStack->data[k].value);
            }

            printf("\n");
        }

       
        else if (postfix[i] == '/') {

            int i1 = popArrayStack(valueStack).value;
            int i2 = popArrayStack(valueStack).value;

            stackElement result;

            result.value = i2 / i1;

            pushArrayStack(valueStack, result);

            printf("- Current: %c | Stack: ", postfix[i]);

            for (int k = 0; k <= valueStack->top; k++) {
                printf("%d ", valueStack->data[k].value);
            }

            printf("\n");
        }

          else if (postfix[i] == '+') {

            int i1 = popArrayStack(valueStack).value;
            int i2 = popArrayStack(valueStack).value;

            stackElement result;

            result.value = i2 + i1;

            pushArrayStack(valueStack, result);

            printf("- Current: %c | Stack: ", postfix[i]);

            for (int k = 0; k <= valueStack->top; k++) {
                printf("%d ", valueStack->data[k].value);
            }

            printf("\n");
        }

        else if (postfix[i] == '-') {

            int i1 = popArrayStack(valueStack).value;
            int i2 = popArrayStack(valueStack).value;

            stackElement result;

            result.value = i2 - i1;

            pushArrayStack(valueStack, result);

            printf("- Current: %c | Stack: ", postfix[i]);

            for (int k = 0; k <= valueStack->top; k++) {
                printf("%d ", valueStack->data[k].value);
            }

            printf("\n");
        }

        i++;
    } 

    int result = popArrayStack(valueStack).value;

    printf("\n- Result: %d\n", result);

    destroyArrayStack(valueStack);

    return result;
}

int precedence(char op) {

    switch (op) {

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