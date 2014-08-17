#ifndef __SORTING_H__
#define __SORTING_H__

typedef int (*sorter_t)(int *items, const int n);

int insertion_sort(int *items, const int n);

int merge_sort(int *items, const int n);

int quick_sort(int *items, const int n);

#endif // __SORTING_H__
