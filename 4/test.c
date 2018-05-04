#include "sorting.c"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long data[1000000];

void CreateData(long maxnum, char* file_name);
void putsResult(char* function_Name, clock_t diff);
void buildBuffer(long* BUFFER);
void printArray(char* FileName, long* arr, long n);

int main(){
    long BUFFER[1000000];
    FILE *fp;
    fp = fopen("Result_Table", "w");
    fputs("Result under 20w\n", fp);
    fclose(fp);
    //now test these sorts with 10,000 integers
    CreateData(10000, "1w");
    
    buildBuffer(BUFFER);
    clock_t start = clock();
    InsertSort(BUFFER, 10000);
	printf("!!");
    clock_t diff = clock() - start;
    putsResult("InsertSort", diff);
    printArray("InsertSort_1w", BUFFER, 10000);
    
    buildBuffer(BUFFER);
    start = clock();
    MergeSort(BUFFER, 0, 10000-1);
    diff = clock() - start;
    putsResult("MergeSort", diff);
    printArray("MergeSort_1w", BUFFER, 10000);

	buildBuffer(BUFFER);
    start = clock();
	QSort(BUFFER, 0, 10000-1);
    diff = clock() - start;
    putsResult("Qsort", diff);
    printArray("QSort_1w", BUFFER, 10000);

	buildBuffer(BUFFER);
    start = clock();
    QSort_Recursion(BUFFER, 0, 10000-1);
    diff = clock() - start;
    putsResult("Qsort_Recursion", diff);

	buildBuffer(BUFFER);
    start = clock();
	CountSort(BUFFER, 10000);
    diff = clock() - start;
    putsResult("CountSort", diff);

	buildBuffer(BUFFER);
    start = clock();
	RadixCountSort(BUFFER, 10000);
    diff = clock() - start;
    putsResult("RadixCountSort", diff);

    //now with 50,000
    CreateData(50000, "5w");
	    buildBuffer(BUFFER);
    start = clock();
    InsertSort(BUFFER, 50000);
    diff = clock() - start;
    putsResult("InsertSort", diff);

    buildBuffer(BUFFER);
    start = clock();
    MergeSort(BUFFER, 0, 50000-1);
    diff = clock() - start;
    putsResult("MergeSort", diff);

    buildBuffer(BUFFER);
    start = clock();
    QSort(BUFFER, 0, 50000-1);
    diff = clock() - start;
    putsResult("Qsort", diff);

    buildBuffer(BUFFER);
    start = clock();
    QSort_Recursion(BUFFER, 0, 50000-1);
    diff = clock() - start;
    putsResult("Qsort_Recursion", diff);

    buildBuffer(BUFFER);
    start = clock();
    CountSort(BUFFER, 50000);
    diff = clock() - start;
    putsResult("CountSort", diff);

    buildBuffer(BUFFER);
    start = clock();
    RadixCountSort(BUFFER, 50000);
    diff = clock() - start;
    putsResult("RadixCountSort", diff);

    //now is 200,000
    CreateData(200000, "20w");
	buildBuffer(BUFFER);
    start = clock();
    InsertSort(BUFFER, 200000);
    diff = clock() - start;
    putsResult("InsertSort", diff);

    buildBuffer(BUFFER);
    start = clock();
    MergeSort(BUFFER, 0, 200000-1);
    diff = clock() - start;
    putsResult("MergeSort", diff);

    buildBuffer(BUFFER);
    start = clock();
    QSort(BUFFER, 0, 200000-1);
    diff = clock() - start;
    putsResult("Qsort", diff);

    buildBuffer(BUFFER);
    start = clock();
    QSort_Recursion(BUFFER, 0, 200000-1);
    diff = clock() - start;
    putsResult("Qsort_Recursion", diff);

    buildBuffer(BUFFER);
    start = clock();
    CountSort(BUFFER, 200000);
    diff = clock() - start;
    putsResult("CountSort", diff);

    buildBuffer(BUFFER);
    start = clock();
    RadixCountSort(BUFFER, 200000);
    diff = clock() - start;
    putsResult("RadixCountSort", diff);

    
    printf("Done!");
    return 0;
}

void CreateData(long maxnum, char* file_name){
    FILE *fp;
    fp = fopen(file_name, "w");
    srand(time(NULL));
    for(long i = 0; i < maxnum; i++){
        data[i] = (long)(rand() / (double)(RAND_MAX) * 1000000);
        fprintf(fp, "%ld ", data[i]);
    }
    fclose(fp);
}

void putsResult(char* function_Name, clock_t diff){
    FILE* fp;
    fp = fopen("Result_Table", "a");
    fputs(function_Name, fp);
    fputs("\t", fp);
    fprintf(fp, "%ldms\n", diff);
    fclose(fp);

}

void buildBuffer(long* BUFFER){
    for(long i=0; i < (sizeof data /sizeof data[0]) ; i++)
        BUFFER[i] = data[i];
}

void printArray(char* FileName, long* arr, long n){
    FILE* fp;
    fp = fopen(FileName, "w");
    for(long i = 0; i < n; i++){
        fprintf(fp, "%ld ", arr[i]);
        printf("%ld ", arr[i]);
    }
    fclose(fp);
}
