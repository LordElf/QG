#ifndef SORTING_H_INCLUDED
#define SORTING_H_INCLUDED

void InsertSort(long arr[], long n);

void MergeSort(long* arr, long left, long right);
void Merge(long* arr, long left, long middle, long right);

void Qsort(long arr[], long n);

void Qsort_Recursion(long arr[], long low, long high);
void swap(long* a, long* b);
long partition(long arr[], long low, long high);

void CountSort(long arr[], long n);

void RadixCountSort(long arr[], long n);
long getMax(long arr[], long n);
void RadixCounting(long arr[], long n, int exp);

#endif
