#include "sorting.h"
#include <stdio.h>
#include <stdlib.h>

void InsertSort(long arr[], long n){
    long i, key, j;
    for(i=1; i < n; i++){
        key = arr[i];
        j=i-1;
        for(;j >= 0 && arr[j] > key;j--)
            arr[j+1] = arr[j];
        arr[j+1] = key;
    }
}

void Merge(long arr[], long left, long middle, long right){
    long LeftLength = middle - left + 1, RightLength = right - middle;
    long BufferLeft[LeftLength], BufferRight[RightLength];
    long i, j, k;
    
    // copy data to the BUFFERS
    for(i=0; i < LeftLength; i++)
        BufferLeft[i] = arr[left + i];
    for(j=0; j < RightLength; j++)
        BufferRight[j] = arr[middle + 1 + j];

    // initialize the indexs
    i = 0;
    j = 0;
    k = left;

    for(;i < LeftLength && j < RightLength ; k++){
        if(BufferLeft[i] <= BufferRight[j]){
            arr[k] = BufferLeft[i];
            i++;
        }
        else{
            arr[k] = BufferRight[j];
            j++;
        }
    }

    //copy the remaining to arr
    for(;i < LeftLength; i++, k++)
        arr[k] = BufferLeft[i];
    for(;j < RightLength; j++, k++)
        arr[k] = BufferRight[j];
}


void MergeSort(long arr[], long left, long right){
    if(left < right){
        long middle = (left + right) / 2;

        MergeSort(arr, left, middle);
        MergeSort(arr, middle + 1, right);

        Merge(arr, left, middle, right);
    }
}

void swap(long* a, long* b) {
        long tmp;
        tmp = *a; 
        *a = *b; 
        *b = tmp;
}

long partition(long arr[], long low, long high) {
        long pivot = arr[high], i = low - 1;
        for (long j = low; j <= high - 1; j++) {
            if (arr[j] <= pivot) {
                i++;
                swap(&arr[i], &arr[j]); 
            }   
        }   
        swap(&arr[i + 1], &arr[high]);
        return i + 1;
}


void QSort(long arr[], long low, long high){
    //create a subStack
    long stack[high - low +1];
    long top = -1;

    stack[++top] = low;
    stack[++top] = high;

    while(top >= 0){
        high = stack[top--];
        low = stack[top--];

        long p = partition(arr, low, high);

        if(p - 1 > low){
            stack[++top] = low;
            stack[++top] = p - 1;
        }
        
        if(p + 1 < high){
            stack[++top] = p + 1;
            stack[++top] = high;
        }
    }
}

void QSort_Recursion(long arr[], long low, long high) {
        if (low < high) {
            long pi = partition(arr, low, high);
            QSort_Recursion(arr, low, pi-1);     
            QSort_Recursion(arr, pi + 1, high);
        }  
}

long getMax(long arr[], long n){
    long curr = 0;
    long max = arr[0];
    
    for(;curr < n; curr++)
        if(arr[curr] > max)
            max = arr[curr];
    return max;
}

void CountSort(long arr[], long n){
    long max = getMax(arr, n), curr;
    long* count = calloc(max + 1, sizeof(long));

    for(curr = 0; curr < max; curr++)
        count[curr] = 0;

    for(curr = 0; curr < n; curr++)
        count[arr[curr]]++;

    long i = 0;
    for(curr = 0; curr <= max; curr++)
        for(long num = 1; num <= count[curr]; num++)
            arr[i++] = curr;
}


void RadixCounting(long arr[], long n, int exp){
    long buffer[n]; 
    long curr, count[10] = {0} ;
    
    //store the occurences
    for(curr = 0; curr < n; curr++)
        count[(arr[curr] / exp)%10]++;
    
    for(curr = 1; curr < 10; curr++)
        count[curr] += count[curr-1];

    for(curr = 0; curr < n; curr++){
        buffer[count[(arr[curr]/exp)%10]-1] = arr[curr];
        count[(arr[curr]/exp)%10]--;
    }

    for(curr = 0; curr < n; curr++)
        arr[curr] = buffer[curr];

}

void RadixCountSort(long arr[], long n){
    long max = getMax(arr, n);

    for(int exp = 1; max/exp > 0; exp *= 10)
        RadixCounting(arr, n, exp);
}

