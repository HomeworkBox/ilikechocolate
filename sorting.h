#ifndef __SORTING_H__
#define __SORTING_H__

typedef int (*sorter_t)(int *items, const int n);

int insertion_sort(int *items, const int n);

int merge_sort(int *items, const int n);

bool merge_sortRecursive(int *items, const int n);

int merge(int *items, const int n,  int k);

void reverse(int *items, int* n);

void exchange(int *head, int* mid, int* right);

int* search(int* head, int target, int range);

int quick_sort(int *items, const int n);

#endif // __SORTING_H__
