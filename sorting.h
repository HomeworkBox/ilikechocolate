//
//  sorting.h
//  cs32 pa2x
//
//  Created by FT: Felicia Truong & Tyler Weimin Ouyang on 8/16/14.
//  Copyright (c) 2014 FT: Felicia Truong & Tyler Weimin Ouyang. All rights reserved.
//

#ifndef __SORTING_H__
#define __SORTING_H__



typedef int (*sorter_t)(int *items, const int n);

int insertion_sort(int *items, const int n);

int merge_sort(int *items, const int n);

bool merge_sortRecursive(int *items, const int n);

void merge(int *items, int* n,  int* k);

void reverse(int *items, int* n);

void exchange(int *head, int* mid, int* right);

int *right_search(int* head, int* tail, const int target);

int *left_search(int* head, int* tail, const int target);

int quick_sort(int *items, const int n);

int *partition(int *left, int *right);

int quicksort_recursive(int *left, int *right);

void quickSort(int arr[], int left, int right);


#endif // __SORTING_H__
