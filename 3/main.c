#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.c"

void M_AQueue();
void M_LQueue();
void stop();

int main(){
    int buffer = 1;
    while(buffer){
        system("clear");
        printf("queue test");
        printf("\n----------------------------------------\n");
        printf("What kind of queue do you want to init?\n");
        printf("1. AQueue\n2. LQueue\n3.other keys to exit\n");
        switch(getchar()){
            case '1': M_AQueue();break;
            case '2': M_LQueue();break;
            default: buffer = 0; break;
        }
         
    }
       
    return 0;
}

void M_AQueue(){
    printf("plz input the data type of a new AQueue\n");
    printf("1.int\n2.long\n3.float\n4.double\n5.char\n");
    scanf("%d", &Data_type_);
    AQueue* Q = (AQueue*)malloc(sizeof(AQueue));
    InitAQueue(Q);
    for(;;){
        stop();
        system("clear");
        printf("implementation of queue");
        printf("\n------------------------\n");
        printf("1.DestoryAQueue\n2.IsFullAQueue\n3.IsEmptyAQueu\n4.GetHeadAQueu    e\n5.LengthAQueue\n6.EnAQueue\n7.DeAQueue\n8.ClearAQueue\n9.APrint\nothes to exit\n");
        switch(getchar()){
            case '1': DestoryAQueue(Q);break;
            case '2': IsFullAQueue(Q) ? printf("YES\n") : printf("NO\n");break;
            case '3': IsEmptyAQueue(Q) ? printf("YES\n") : printf("NO\n");break;
            case '4': ;
                    void* e = malloc(sizeof(Q->data_size));
                    GetHeadAQueue(Q, e);
                    printf("Head is: ");
                    APrint(e);
                    printf("\n");
                    break;
            case '5': ;
                    int length;
                    length = LengthAQueue(Q);
                    printf("the length is %d \n", length);
                    break;
            case '6':;
                   printf("input data:\t");
                   void* a = malloc(sizeof(Q->data_size));
                   switch(Data_type_){
                       case 1: ;
                               scanf("%d", (int*)a);
                               break;
                       case 2: ;
                               scanf("%ld", (long*)a);
                               break;
                       case 3: ;
                               scanf("%f", (float*)a); 
                               break;
                       case 4: ;
                               scanf("%lf", (double*)a); 
                               break;
                       case 5: ;
                               scanf("%c", (char*)a);
                               break;
                       default: printf("Invalue data type");
                                break;
                   }
                   EnAQueue(Q, (void*)a) ? printf("SUCCEED\n") : printf("Unknown Error\n");
                   break;
            case '7': DeAQueue(Q); break;
            case'8' : ClearAQueue(Q); break;
            case '9': TraverseAQueue(Q, &APrint); break;
            default:  return;
        }
        stop();
    }
}

void M_LQueue(){
    printf("plz input the data type of a new LQueue\n");
    printf("1.int\n2.long\n3.float\n4.double\n5.char\n");
    scanf("%d", &Data_type_);
    LQueue* Q = (LQueue*)malloc(sizeof(LQueue));
    InitLQueue(Q);

    while(1){
        stop();
        system("clear");
        printf("implementation of queue");
        printf("\n------------------------\n");
        printf("1.DestoryLQueue\n2.IsEmptyLQueu\n3.GetHeadLQueue\n4.LengthLQueue\n5.EnLQueue\n6.DeLQueue\n7.ClearLQueue\n8.LPrint\n");
        switch(getchar()){
            case '1': DestoryLQueue(Q);break;
            case '2': IsEmptyLQueue(Q) ? printf("YES\n") : printf("NO\n");break;
            case '3': ;
                    void* e = malloc(sizeof(Q->data_size));
                    GetHeadLQueue(Q, e);
                    printf("Head is: ");
                    LPrint(e);
                    printf("\n");
                    break;
            case '4': ;
                    int length;
                    length = LengthLQueue(Q);
                    printf("the length is %d \n", length);
                    break;
            case '5':;
                    printf("input data:\t");
                    void* a = malloc(sizeof(Q->data_size));
                    switch(Data_type_){
                       case 1: ;
                               scanf("%d", (int*)a);
                               break;
                       case 2: ;
                               scanf("%ld", (long*)a);
                               break;
                       case 3: ;
                               scanf("%f", (float*)a); 
                               break;
                       case 4: ;
                               scanf("%lf", (double*)a); 
                               break;
                       case 5: ;
                               scanf("%c", (char*)a);
                               break;
                       default: printf("Invalue data type");
                                break;
                   }
                   EnLQueue(Q, (void*)a) ? printf("SUCCEED\n") : printf("Unknown Error\n");
                   break;
            case '6': DeLQueue(Q); break;
            case '7': TraverseLQueue(Q, &LPrint); break;
            default: printf("ERROR"); return;
        }
    }
}

void stop(){
    printf("press any key to continue\n");
    getchar();
}
