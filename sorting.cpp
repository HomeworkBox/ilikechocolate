//
//  sorting.cpp
//  cs 32 pa2x
//
//  Created by FT: Felicia Truong & Tyler Weimin Ouyang on 8/16/14.
//  Copyright (c) 2014 FT: Felicia Truong & Tyler Weimin Ouyang. All rights reserved.
//


#include <iostream>
#include "sorting.h"
using namespace std;

// Insertion Sort:
int insertion_sort(int *items, const int n) {
    if (n < 0 || items == NULL) {
        return 1;
    }
    int temp, i, j;
    int nn=n-1;
    for (i=0; i<nn; i++){
        if (items[i] > items[i+1]) {
            temp = items[i+1];
            j=i;
            while ( j>=0 && items[j] > temp){
                items[j+1]=items[j];
                j--;
            }
            items[j+1]=temp;
        }
    }
    return 0;
}

int merge_sort(int *items, const int n) {
    if (n < 0 || items == NULL) {
        return 1;
    }
    
    
    else if (n <= 6) {
        insertion_sort(items, n);
    }
    else
    {
        int half = n/2;
        merge_sortRecursive(items, half);
        merge_sortRecursive(items+half, n-half);
        merge(items, items+half, items+n);
    }
    
//    else if (n%2 != 0) {
//        merge_sortRecursive(items, n/2+1);
//        merge_sortRecursive(items + n/2+1, n/2);
//        merge (items, items+n/2+1, items+n-1);
//    }
//    else {
//        merge_sortRecursive(items, n/2);
//        merge_sortRecursive(items + n/2, n/2);
//        merge (items, items+ n/2, items+n-1);
//        
//    }
//    for (int z=0; z<n; z++)
//        cout << items[z] << "\n";
//    cout << '\n';// test output
//    mergesort2(items, n);
    return 0;
    
}

bool merge_sortRecursive(int *items, const int n){
    if (n <= 6) {
        insertion_sort(items, n);
        return 0;
    }
    else
    {
        int h = n/2;
        merge_sortRecursive(items, h);
        merge_sortRecursive(items+h, n-h);
        merge(items, items+h, items+n);
    }    return 0;
}

void merge(int* head, int* mid, int* tail){
    
    int n1 = mid - head;
    int n2 = tail - mid;
    
    if (n1 == 0 || n2 == 0)
        return;
    if (n1 == 1 && n2 == 1)
    {
        if (*mid < *head) {
            int key = *head;
            *head = *mid;
            *mid = key;
        }
    }
    else
    {
        int* p, * q;
        
        if (n1 <= n2)
            p = right_search(head, mid, *(q = mid+n2/2));
        else
            q = left_search(mid, tail, *(p = head+n1/2));
        
        exchange(p, mid, q);
        mid = q-mid+p;
        merge(head, p, mid);
        merge(mid, q, tail);
    }
}



// Quick Sort:
int quick_sort(int *items, const int n) {
    if (n < 0 || items == NULL) {
        return 1;
    }
    else if (n <= 6) {
        return insertion_sort(items, n);
    }
    else {
        int * pivot=partition(items, items+n-1);
        quicksort_recursive(items, pivot-1);
        quicksort_recursive(pivot+1, items+n-1);
        
    }
    return 0;
}

int quicksort_recursive(int *left, int *right){
    int n=right - left + 1;
    if (n <= 6) {
        return insertion_sort(left, n);
    }
    else {
        int * pivot=partition(left, right);
        quicksort_recursive(left, pivot-1);
        quicksort_recursive(pivot+1, right);
        
    }
    return 0;
}

//helpers

int *partition(int *left, int *right){
    int *pivot=left + (right - left )/2;
    int temp1=0, *lp=left, *rp=right;
    while (lp < rp) {
        while (*lp < *pivot) {
            lp++;
        }
        while (*rp > *pivot) {
            rp--;
        }
        if (lp < rp) {
            temp1 = *lp;
            *lp = *rp;
            *rp = temp1;
            if (pivot==lp){
                pivot=rp;
                lp++;
            }
            else if(pivot == rp){
                pivot=lp;
                rp--;
            }
        }
    }
    return pivot;
}

void reverse(int* a, int* b)
{
    int *left = a;
    int *right = b-1;
    while(left < right)
    {
        int temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }
}

void exchange(int *head, int* mid, int* right){
    if (head==mid || mid == right) {
        return;
    }
    reverse(head, mid);
    reverse(mid, right);
    reverse(head, right);
}

int *left_search(int* head, int* tail, const int target){
    int i;
    for ( i = tail-head; i != 0; i /= 2 )
    {
        int* mid = head + i/2;
        if (*mid < target)
            head = mid + 1, i--;
    }
    return head;
}
int *right_search(int* head, int* tail, const int target) {
    int i;
    for ( i = tail-head; i != 0; i /= 2 )
    {
        int* mid = head + i/2;
        if (*mid <= target)
            head = mid + 1, i--;
    }
    return head;
}

/*
     int* search(int* head, int target, int range){     if (range <= 10 ) {
        if (target<head[0])
            return head;
        int i;
        for (i=0; i< range-1; i++) {
            if (head[i] <= target && head[i+1]> target) {
                return head+i+1;
            }
        }
        return head+range;
        
    }
    else if (target < head[range/2]) {
        return search( head, target, range/2);
    }
    else if (target > head[range/2]){
        if (range%2!=0)
            return search( head+range/2+1, target, range/2);
        else
            return search( head+range/2+1, target, range/2-1);
    }
    else if (target == head[range/2]){
        int i;
        for ( i=range/2+1; target == head[i]; i++) ;
        
        return head+i;
        
    }
    return head; 
     }
     */



