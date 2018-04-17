#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

//顺序栈(基于数组的)
Status initStack(SqStack *s,int sizes)  //初始化链表
{
	s->elem = (ElemType *)malloc(sizes * sizeof(ElemType));
	if (NULL == s)
		return ERROR;
	s->top = -1;
	s->size = sizes;
	return OK;
}


Status isEmptyStack(SqStack *s)   //判断链表是否为空
{
	return (-1 == s->top ? OK : ERROR);
}


Status getTopStack(SqStack *s,ElemType *e)   //得到链表头元素
{
	if (NULL == s || -1 == s->top)
		return ERROR;
	else
		*e = s->elem[s->top];
	return OK;
}


Status clearStack(SqStack *s)   //清空链表
{
    if(NULL == s)
        return ERROR;
	s->top = -1;
    return OK;
}


Status destroyStack(SqStack *s)  //销毁链表
{
	if (NULL == s)
		return ERROR;
	free(s->elem);
	return OK;
}


Status stackLength(SqStack *s,int length)   //检测链表长度
{
	if(NULL == s)
		return ERROR;
	length = s->top + 1;
	return OK;
}

Status pushStack(SqStack *s,ElemType datas)  //入栈
{
	if (s->top >= s->size - 1 || NULL == s)
		return ERROR;
	s->top++;
    s->elem[s->top] = datas;
	return OK;
}

Status popStack(SqStack *s,ElemType *datas)   //出栈
{
	if (NULL == s || -1 == s->top)
		return ERROR;
	*datas = s->elem[s->top];
	s->top--;
	return OK;
}

//链栈(基于链表的)
Status initLStack(LinkStack *s)   //初始化
{
	s->top = (LinkStackPtr)malloc(sizeof(StackNode));
	if(NULL == s->top)
		return ERROR;
	s->count = 0;
	s->top->next=NULL;
	return OK;
}

Status isEmptyLStack(LinkStack *s)  //判断链表是否为空
{
	return(NULL == s->top ? OK : ERROR);
}

Status getTopLStack(LinkStack *s,ElemType *e)  //得到链表头元素
{
	if(NULL == s || NULL == s->top)
		return ERROR;
    LinkStackPtr p = s->top;
	for(; p->next != NULL; p = p->next);
	*e = p->data;
	return OK;
}

Status clearLStack(LinkStack *s)   //清空链表
{
	return (destroyLStack(s) && initLStack(s) ? OK : ERROR);
}

Status destroyLStack(LinkStack *s)   //销毁链表
{
	if(NULL == s)
		return ERROR;
    LinkStackPtr tmp = (LinkStackPtr)malloc(sizeof(StackNode));
	for(LinkStackPtr p = s->top ; s->count != 0 ; *tmp = *p, p = p->next, free(tmp), s->count--);
	return OK;
}

Status LStackLength(LinkStack *s,int *length)    //检测链表长度
{
	if(NULL == s)
		return ERROR;
	*length = s->count;	
	return OK;
}

Status pushLStack(LinkStack *s,ElemType datas)   //入栈
{
	s->count++;
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
	p->next = s->top;
	p->data = datas;
	s->top = p;
	return OK;
}

Status popLStack(LinkStack *s,ElemType *datas)   //出栈
{
	if(NULL == s || NULL == s->top)
		return ERROR;
	*datas = s->top->data;
	s->count--;
	LinkStackPtr tmp = s->top;
	s->top = s->top->next;
	free(tmp);
	return OK;
}
