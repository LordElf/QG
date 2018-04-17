#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFFER_SIZE 128

typedef enum Status
{
	ERROR = 0, OK = 1
}Status;

typedef float VaElem;
typedef char OpElem;

typedef struct SqStack {
	VaElem* elem;
	int top;    
}VaStack;

typedef struct OpStack {
	OpElem* elem;
	int top;
}OpStack;

Status initVaStack(VaStack *s) 
{
	s->elem = (VaElem *)malloc(BUFFER_SIZE * sizeof(VaElem));
	if (NULL == s)
		return ERROR;
	s->top = -1;
	return OK;
}

Status initOpStack(OpStack *s)
{
	s->elem = (OpElem *)malloc(BUFFER_SIZE * sizeof(OpElem));
	if (NULL == s)
		return ERROR;
	s->top = -1;
	return OK;
}

Status isEmptyVaStack(VaStack *s)  
{
	return (-1 == s->top ? OK : ERROR);
}

Status isEmptyOpStack(OpStack *s)
{
	return (-1 == s->top ? OK : ERROR);
}

Status pushVaStack(VaStack *s, VaElem datas) 
{
	s->top++;
	s->elem[s->top] = datas;
	return OK;
}

Status pushOpStack(OpStack *s, OpElem datas)
{
	s->top++;
	s->elem[s->top] = datas;
	return OK;
}

VaElem popVaStack(VaStack *s) 
{
	s->top--;
	return s->elem[s->top];
}

OpElem popOpStack(OpStack *s)
{
	s->top--;
	return s->elem[s->top];
}

float calculate(float a, float b, char c) {
	switch (c)
	{
	case '+': return b + a;
	case '-': return b - a;
	case '*': return b * a;
	case '/': 
		if (a - 0.000001 <= 0) {
			printf("ERROR\n");
			return ERROR;
		}
		return b / a;
    default :
        return 0;
	}
}

//ÅÐ¶Ï·ûºÅÓÅÏÈ¼¶
Status hasPrecedence(char op1, char op2) {
	if (op2 == '(' || op2 == ')')
		return ERROR;
	if ((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-'))
		return ERROR;
	else
		return OK;
}

int main(){
	char Token[BUFFER_SIZE], *buffer;
	printf("please input the equation you want to calculate\n");
	printf("use * as a substitude of x and no = at the end\n");
	fgets(Token, BUFFER_SIZE, stdin);//·ÀÖ¹Òç³ö
	VaStack* vs = (VaStack*)malloc(sizeof(VaStack));
	OpStack* os = (OpStack*)malloc(sizeof(OpStack));
	initVaStack(vs);
	initOpStack(os);
	for (int i = 0, j = 0; Token[i] != '\0'; i++) {

		//current token is a number, push it to VaStack
		if (Token[i] >= '0' && Token[i] <= '9'){
            buffer = (char*)malloc(BUFFER_SIZE * sizeof(char));
            while(i < strlen(Token) && Token[i] >= '0' && Token[i] <= '9')
                buffer[j++] = Token[i++];
            pushVaStack(vs, atof(buffer));
            free(buffer);
                
        }

		//current token is left parenthesis, push it to OpStack
		else if (Token[i] == '(') {
			pushOpStack(os, Token[i]);
		}

		//current token is right parenthesis, calculate the equation in '()'
		else if (Token[i] == ')') {
			while (os->elem[os->top] != '(')
				pushVaStack(vs, calculate(popVaStack(vs), popVaStack(vs), popOpStack(os)));
		}

		//current token is an operator
		else if (Token[i] == '+' || Token[i] == '-' || Token[i] == '*' || Token[i] == '/') {
			// While top of Opstack has same or greater precedence to current
			// token, which is an operator. Apply operator on top of OpStack
			// to top two elements in values stack
			while (!isEmptyOpStack(os) && hasPrecedence(Token[i], os->elem[os->top]))
				pushVaStack(vs, calculate(popVaStack(vs), popVaStack(vs), popOpStack(os)));

			// push the current operator to OpStack
			pushOpStack(os, Token[i]);
		}
	}

	while(!isEmptyOpStack(os))
		pushVaStack(vs, calculate(popVaStack(vs), popVaStack(vs), popOpStack(os)));

	//top of value is the result
	if (vs->top == 0)
		printf(" = %f\n", popVaStack(vs));
	else printf("some errors occured\n");
	return 0;
}
