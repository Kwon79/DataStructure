#include<stdio.h>
#include<stdlib.h>

#include"LinkedStack.h"

void printMenu(){
    printf("----------------------------------------------------------\n");
    printf("1. URL 추가: URL을 입력받아 스택에 URL을 추가\n");
    printf("2. URL 제거: URL을 입력받아 스택에서 URL을 제거\n");
    printf("3. 스택 확인: 현재 스택에 저장된 URL의 마지막 값을 출력\n");
    printf("----------------------------------------------------------\n");
    printf("번호 선택:");
}

int main() {
    LinkedStack* myStack = createLinkedStack();
    int choi;
    stackElement URL;
    stackElement current;

    while (1) {
        printMenu();
        scanf_s("%d", &choi);
        getchar();

        switch (choi) {
        case 1:
            printf("URL입력:");
            fgets(URL, sizeof(URL), stdin);
            URL[strlen(URL) - 1] = '\0';
            pushLinkedStack(myStack, URL);
            peekStack(myStack, current);
            printf("현재 주소:%s\n", current);
            break;
        case 2:
            if (emptyLinkedStack(myStack)) {
                printf("열린 창이 없습니다.\n");
                break;
            }
            peekStack(myStack, current);
            printf("이탈:%s\n",current);
            popLinkedStack(myStack);
            if (emptyLinkedStack(myStack)) {
                printf("브라우저를 종료합니다.\n");
                destroyLinkedStack(myStack);
                return 0;
            }else
            {
                peekStack(myStack, current);
                printf("현재창:%s\n", current);
            }
            break;
        case 3:
            if (emptyLinkedStack(myStack)) {
                printf("열린 창이 없습니다.\n");
                break;
            }
            else
            {
                peakStack(myStack, current);
                printf("현재 주소:%s\n", current);
                break;
            }
        default:
            printf("메뉴에 있는 번호를 입력하세요.\n");
            break;
        }
    }
}