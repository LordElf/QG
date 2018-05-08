#include "BinaryTree.h"
#include <stdlib.h>
#include <stdio.h>

#define MAX_Q_SIZE 512

BiTNode** createQueue(int *, int *);
void enQueue(BiTNode **queue, int *rear, BiTNode *new_node);
BiTNode *deQueue(BiTNode **queue, int *front);

Status IsOper(BiTree T);

Status InitBiTree(BiTree T){
    T = (BiTree)malloc(sizeof(BiTree));
    T -> lchild = NULL;
    T -> rchild = NULL;
    return SUCCESS;
}

Status DestroyBiTree(BiTree T){
    if(T != NULL){
        DestroyBiTree(T->lchild);
        DestroyBiTree(T->rchild);
        free(T);
    }            
    return SUCCESS;
}

Status IsOper(BiTree T){
    switch (T->data){
        case '+':
        case '-':
        case '*':
        case '/': return SUCCESS;
        default : return ERROR;
    }
}
Status CreateBiTree(BiTree* T, char* definition){
    static int t=1;
    if(definition == NULL)
        return ERROR;
    BiTree tmp = (BiTree)malloc(sizeof(BiTree));
    InitBiTree(tmp);        
    tmp -> data = *definition;
    *T = tmp;
    if(IsOper(*T)){
        CreateBiTree(&(T[0]->lchild), definition + t++);
        CreateBiTree(&(T[0]->rchild), definition + t++);
    }
    return SUCCESS;
}

Status preVisit(BiTNode* node){
    if(node == NULL)
        return ERROR;
    printf("%c", node->data);
    preVisit(node -> lchild);
    preVisit(node -> rchild);
    return SUCCESS;
}

Status postVisit(BiTNode* node){
    if(node == NULL)
        return ERROR;
    postVisit(node->lchild);
    postVisit(node->rchild);
    printf("%c ", node->data);
    return SUCCESS;
}

Status inVisit(BiTNode* node){
    if(node == NULL)
        return ERROR;
    inVisit(node->lchild);
    printf("%c", node->data);
    inVisit(node->rchild);
    return SUCCESS;
}

Status LevelOrderVisit(BiTNode* root)
{
    int rear, front;
    BiTNode **queue = createQueue(&front, &rear);
    BiTNode *temp_node = root;
 
    while (temp_node)
    {
        printf("%c ", temp_node->data);
 
        /*Enqueue lchild child */
        if (temp_node->lchild)
            enQueue(queue, &rear, temp_node->lchild);
 
        /*Enqueue rchild child */
        if (temp_node->rchild)
            enQueue(queue, &rear, temp_node->rchild);
 
        /*Dequeue node and make it temp_node*/
        temp_node = deQueue(queue, &front);
    }
    return SUCCESS;
}
 
/*UTILITY FUNCTIONS*/
BiTNode** createQueue(int *front, int *rear)
{
    BiTNode **queue = (BiTNode **)malloc(sizeof(BiTNode*)*MAX_Q_SIZE);
 
    *front = *rear = 0;
    return queue;
}
 
void enQueue(BiTNode **queue, int *rear, BiTNode *new_node)
{
    queue[*rear] = new_node;
    (*rear)++;
}
 
BiTNode *deQueue(BiTNode **queue, int *front)
{
    (*front)++;
    return queue[*front - 1];
}

int Value(BiTNode* T){
    if(IsOper(T))
        switch(T->data){
            case '+': return Value(T->lchild) + Value(T->rchild);
            case '-': return Value(T->lchild) - Value(T->rchild);
            case '*': return Value(T->lchild) * Value(T->rchild);
            case '/': return Value(T->lchild) / Value(T->rchild);
        }
    return (T->data - '0');
}
