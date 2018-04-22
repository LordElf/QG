#include "queue.h"
static int Data_type_ = 0;

void InitAQueue(AQueue *Q){
    switch(Data_type_){
    case 1: Q->data_size = sizeof(int); break; 
    case 2: Q->data_size = sizeof(long); break;
    case 3: Q->data_size = sizeof(float); break;
    case 4: Q->data_size = sizeof(double); break;
    case 5: Q->data_size = sizeof(char); break;
    default: printf("error\n");
             return;
    }
    int i;
    for(i = 0; i < MAXQUEUE; i++)
        Q->data[i] = malloc(Q->data_size);
    Q-> front = Q-> rear = -1;
    return;
}

void InitLQueue(LQueue* Q){
    switch(Data_type_){
    case 1: Q->data_size = sizeof(int);  break;
    case 2: Q->data_size = sizeof(long); break;
    case 3: Q->data_size = sizeof(float); break;
    case 4: Q->data_size = sizeof(double); break;
    case 5: Q->data_size = sizeof(char); break;
    default: printf("error\n");
             return;

    }
    Q->front->data = malloc(Q->data_size); 
    Q->rear = Q->front = NULL;
    return;
}

void DestoryAQueue(AQueue *Q){
    int i;
    for(i = 0; i < MAXQUEUE; i++){
        free(Q->data[i]);
        Q->data[i] = NULL;
    }
    Q-> front = Q-> rear = 0;
    return;
}

void DestoryLQueue(LQueue *Q){
    Node* tmp = Q->front;
    for(; Q->front != Q->rear; tmp = Q->front){
        Q->front = tmp->next;
        free(tmp);
        tmp = NULL;
    }
    free(Q->front);
    Q->front = Q->rear = NULL;
    return;
}

Status IsFullAQueue(const AQueue *Q){
    return(((0 == Q->front && Q->rear == MAXQUEUE-1) || Q->rear == Q->front-1) ? TRUE : FALSE);
}

Status IsEmptyAQueue(const AQueue *Q){
    return(Q->front == -1 ? TRUE : FALSE);
}

Status IsEmptyLQueue(const LQueue *Q){
    return(NULL == Q->front? TRUE : FALSE);
}

Status GetHeadAQueue(AQueue *Q, void *e){
    if(IsEmptyAQueue(Q))
        return FALSE;
    memcpy(e, Q->data[Q->front], Q->data_size);
    return TRUE;
}

Status GetHeadLQueue(LQueue *Q, void *e){
    if(IsEmptyLQueue(Q))
        return FALSE;
    memcpy(e, Q->front->data, Q->data_size);
    return TRUE;
}

int LengthAQueue(AQueue *Q){
    return Q->rear - Q->front + 1;
}

int LengthLQueue(LQueue *Q){
    int count = 0;
    Node* tmp = Q->front;
    while(tmp != Q->rear){
        count++;
        tmp = tmp->next;
    }
    return count;
}

Status EnAQueue(AQueue *Q, void *data){
    if(IsFullAQueue(Q)){
        printf("This queue is full");
        return FALSE;
    }

    else if(IsEmptyAQueue(Q)){
        Q->front = Q->rear = 0;
        memcpy(Q->data[Q->rear], data, Q->data_size);
    }
     
    //if rear reaches the end of the array while the queue is not empty
    else if(Q->front != 0 && Q->rear == MAXQUEUE - 1){
        Q->rear = 0;
        memcpy(Q->data[Q->rear], data, Q->data_size);
    }

    else {
       Q->rear++;
       memcpy(Q->data[Q->rear], data, Q->data_size);
    }
    return TRUE;
}

Status EnLQueue(LQueue *Q, void *data){
    Node* p = malloc(sizeof(LQueue));
    memcpy(p, data, Q->data_size);
    if(Q->front == NULL)
        Q->front = p;
    Q->rear->next = p;
    Q->rear = p;
    p->next = Q->front;
    return TRUE;
}

Status DeAQueue(AQueue *Q){
    if(IsEmptyAQueue(Q))
        return FALSE;
    
    //if there's only one element in queue, make the queue empty after dequeue 
    if(Q->front == Q->rear)
        Q->front =Q->rear =-1;

    else if(Q->front == MAXQUEUE - 1)
        Q->front = 0;
    
    else 
        Q->front++;
    
    return TRUE;
}

Status DeLQueue(LQueue *Q){
    if(IsEmptyLQueue(Q))
        return FALSE;
    Node* tmp = Q->front;
    LPrint(tmp->data);
    printf("left the queue");
    Q->front = tmp->next;
    free(tmp);
    return TRUE;
}

void ClearAQueue(AQueue *Q){
    Q-> front = Q-> rear = 0;
    return;

}

void ClearLQueue(LQueue *Q){
    Node* tmp = Q->front;
    for(; Q->front != Q->rear; tmp = Q->front){
        Q->front = tmp->next;
        free(tmp);
        tmp = NULL;
    }
    Q->front = Q->rear = NULL;
    return;
}

Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q)){
    if(IsEmptyAQueue(Q)){
        printf("The queue is empty");
        return FALSE;
    }
    
    if(Q->rear >= Q->front)
        for(int i = Q->front; i <= Q->rear; i++)
            foo(Q->data[i]);
    else {
        for(int i = Q->front; i < MAXQUEUE; i++)
            foo(Q->data[i]);
        for(int i = 0; i <= Q->rear; i++)
            foo(Q->data[i]);
    }
    return TRUE;
}

Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)){
    if(IsEmptyLQueue(Q))
        return FALSE;

    for(Node* tmp = Q->front; tmp != Q->rear ;tmp = tmp->next)
        foo(Q->front->data);
    foo(Q->front->data);
    return TRUE;
}

void APrint(void *q){
    switch(Data_type_){
    case 1: printf("%d ", *(int*)q);return;
    case 2: printf("%ld ", *(long*)q);return;
    case 3: printf("%f ", *(float*)q);return;
    case 4: printf("%lf ", *(double*)q);return;
    case 5: printf("%c ", *(char*)q);return;
    default : printf("ERROR"); return;
    }
}

void LPrint(void *q){
    switch(Data_type_){
    case 1: printf("%d ", *(int*)q);return;
    case 2: printf("%ld ", *(long*)q);return;
    case 3: printf("%f ", *(float*)q);return;
    case 4: printf("%lf ", *(double*)q);return;
    case 5: printf("%c ", *(char*)q);return;
    default : printf("ERROR"); return;
    }
}

