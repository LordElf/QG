#include "BinaryTree.c"
#include <stdlib.h>
#include <stdio.h>

int main(){
    printf("Welcomes!");
    int w = 0;
    for(char i = 0;;system("clear")){
        printf("1.create a binary tree\n2.DestroyBiTree\n3.PreVisit\n4.postVisit\n5.inVisit\n6.LevelOrderVisit\n7.Value\nother keys to leave\n");
        scanf("%c", &i);
        BiTree T = (BiTree)malloc(sizeof(BiTree));
        switch(i) {
            case '1': if(w == 0){
                        puts("please input a Prefix Expression");
                        char E[512];
                        scanf("%s", E);
                        CreateBiTree(&T, E);
                        w = 1;
                        printf("Done");
                        getchar();
                    }
                    else printf("You've already created a BiTree, pleasr Destroy it first if you want to create a new one\n");
                    break;

            case '2': DestroyBiTree(T);
                      w=0;
                      getchar();
                      break;
            case '3':preVisit(T);
                     getchar();
                     break;
            case'4': postVisit(T);
                     getchar();
                     break;
            case'5': inVisit(T);
                     getchar();
                     break;
            case'6': LevelOrderVisit(T);
                     getchar();
                     break;
            case '7': Value(T);
                      getchar();
                      break;
            default: return 0;
        }
        puts("\npress any keys to continue\n");

        getchar();
    }
}
