#include "stack.c"
#include <stdlib.h>
#include <stdio.h>

void manipulateO(void);
void manipulateL(void);

int main() {
	int i, m=1;
	while (m == 1) {
		printf("stack operation\n");
		printf("-------------------------------\n");
		printf("1. init an order stack\n2. init a linked stack\n3. exit\n");
		printf("please input a NO\n");
		scanf("%d", &i);
		switch (i) {
		case 1:
			manipulateO();
			break;
		case 2:
			manipulateL();
			break;
		case 3:
			m = 0;
			break;
		}
	}
	return 0;
}

void manipulateO(void) {
	int size;
	SqStack* s = (SqStack*)malloc(sizeof(SqStack));
	printf("Plz input the size of stack: ");
	scanf("%d", &size);
	if (ERROR == initStack(s,size))
		return;
	int i;
	for (;;) {
		printf("\nWhat do you want to mainpulate this OrderStack?\n");
		printf("------------------------------------------------\n");
		printf("1. isEmptyStack\n2. getTopStack\n3. clearStack\n4.destoryStack\n5.stackLength\n6.pushStack\n");
		printf("7.popStack \n8.exit\n");
		printf("please input a NO");
		scanf("%d", &i);
		switch (i) {
			case 1:
				isEmptyStack(s) == OK ? printf("YES\n") : printf("NO\n");
				break;
			case 2:
				;
				ElemType *top = (ElemType* )malloc(sizeof(ElemType));
				getTopStack(s, top) == OK ? printf("OK\n") : printf("ERROR\n");
				printf("top element is %d", *top);
				break;
			case 3:
				clearStack(s) == OK ? printf("OK\n") : printf("ERROR\n");
				break;
			case 4:
				destroyStack(s) == OK ? printf("OK\n") : printf("ERROR\n");
				break;
			case 5:
				;
				int length = 0;
				stackLength(s, length) == OK ? printf("OK\n") : printf("ERROR\n");
				printf("length of the stack is %d", length);
				break;
			case 6:
				;
				ElemType data;
				printf("input data U want to push into the stack");
				scanf("%d", &data);
				pushStack(s,data) == OK ? printf("OK\n") : printf("ERROR\n");
				break;
			case 7:
				;
				ElemType* datas = (ElemType* )malloc(sizeof(ElemType));
                int j = popStack(s, datas);
				j == OK ? printf("OK\n") : printf("ERROR\n");
				if(j)
                    printf("the element just poped out is %d", *datas);
				break;
			case 8:
				return;
		}
	}
}

void manipulateL(void) {
	int i;
	LinkStack* s = (LinkStack*)malloc(sizeof(LinkStack));
	for (;;) {
		printf("\nWhat do you want to mainpulate this LinkStack?\n");
		printf("----------------------------------------------\n");
		printf("1. isEmptyLStack\n2. getTopLStack\n3. clearLStack\n4. destroyLStack\n5. LStackLength\n");
		printf("6. pushLStack\n7. popLStack\n8. exit\n");
		printf("please input a NO");
		scanf("%d", &i);

		switch (i) {
			case 1:
				isEmptyLStack(s) == OK ? printf("YES\n") : printf("NO\n");
				break;
			case 2:
				;
				ElemType* top = (ElemType* )malloc(sizeof(ElemType));
				getTopLStack(s, top) == OK ? printf("OK\n") : printf("ERROR\n");
				break;
			case 3:
				clearLStack(s) == OK ? printf("OK\n") : printf("ERROR\n");
				break;
			case 4:
				destroyLStack(s) == OK ? printf("OK\n") : printf("ERROR\n");
				break;
			case 5:
				;
				int* length = (int*)malloc(sizeof(int));
				LStackLength(s, length) == OK ? printf("OK\n") : printf("ERROR\n");
				printf("length of the stack is %d", *length);
				break;
			case 6:
				;
				ElemType data;
				printf("input data U want to push into the stack");
				scanf("%d", &data);
				pushLStack(s, data) == OK ? printf("OK\n") : printf("ERROR\n");
				break;
			case 7:
				;
				ElemType* datas = (ElemType* )malloc(sizeof(ElemType));
                int j = popLStack(s, datas);
				j == OK ? printf("OK\n") : printf("ERROR\n");
                if(j)
				printf("the element just poped out is %d", *datas);
				break;
			case 8:
			return;
		}
	}
}
