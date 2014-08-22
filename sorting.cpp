// Tyler Weimin Ouyang 2014-08-15
// cs32 pa2

#include <iostream>
#include "sorting.h"
#include "experimental.h"
using namespace std;


// Insertion Sort:
int insertion_sort(int *items, const int n) {
    
    if (n < 0 || items == NULL) {
        return 1;
    }
    int temp, i, j;
    int nn=n-1;
    for (i=0; i<nn; i++){
        //        if (typeid(items[i]) != typeid(int())) {
        //            return 1;
        //        }
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

// Merge Sort:
void merge(int* a, int* b, int* c){
    //    int *left = items;
    //    int *right = items+n-1;
    //    int *mid = items+k;
    //    int n1 = k;
    //    int n2 = n-k; // bounds
    //
    //    if (n1 == 0 || n2 == 0)
    //        return;
    //    if (n1 == 1 && n2 == 1) {
    //        if (*mid < *left){
    //            int key = *left;
    //            *left = *right;
    //            *right = key;
    //        }
    //    }
    //    else {
    //        int* p, * q;
    //
    //        if (n1 <= n2)
    //            p = search(left, *(q=mid+n2/2), k);
    //        else
    //            q = search(mid, *(p=left+n1/2), n-k)-1; // bounds
    //
    //        exchange(p, mid, q);
    //        mid = q-mid+p;
    //        merge(left, mid-items+1, p-left);
    //        merge(mid, right - mid+1, q-mid);
    //    }
    //    return ;
    int n1 = b - a;
    int n2 = c - b;
    
    if (n1 == 0 || n2 == 0)
        return;
    if (n1 == 1 && n2 == 1)
    {
        if (*b < *a) {
            int key = *a;
            *a = *b;
            *b = key;
        }
    }
    else
    {
        int* p, * q;
        
        if (n1 <= n2)
            p = search(a, *(q=b+n2/2), b-a);
        else
            q = search(b, *(p=a+n1/2), c-b)-1;
        exchange(p, b, q);
        b= q-b+p;
        merge(a, p, b);
        merge(b, q, c);
    }
}
int merge_sort(int *items, const int n) {
    if (n < 0 || items == NULL) {
        return 1;
    }
//    int times = n/6;
//    int remainder = n%6;
//    
//    for (int i=0; i<times; i++){
//        insertion_sort(&items[i*6], 6);
//    }
//    insertion_sort(&items[n-remainder-1], remainder); // remainder-1??

    
    else if (n <= 6) {
        insertion_sort(items, n);
    }
    else if (n%2 != 0) {
        merge_sortRecursive(items, n/2+1);
        merge_sortRecursive(items + n/2+1, n/2);
        merge (items, items+n/2, items+n-1);
    }
    else {
        merge_sortRecursive(items, n/2);
        merge_sortRecursive(items + n/2, n/2);
        merge (items, items+ n/2, items+n-1);

    }
//    for (int z=0; z<n; z++)
//        cout << items[z] << "\n";
//    cout << '\n';// test output
    //mergesort2(items, n);
    return 0;

}

bool merge_sortRecursive(int *items, const int n){
    if (n <= 6) {
         insertion_sort(items, n);
//        for (int z=0; z<n; z++)
//            cout << items[z] << " ";
//        cout << '\n';
        return 0;
    }
    else if (n%2 != 0) {
        merge_sortRecursive(items, n/2+1);
        merge_sortRecursive(items + n/2 +1, n/2);
        
        merge (items, items+n/2+1, items+n-1);
        for (int z=0; z<n; z++)
            cout << items[z] << " ";
        cout << '\n';

    }
    else {
        merge_sortRecursive(items, n/2);
        merge_sortRecursive(items + n/2, n/2);

        merge (items, items+ n/2, items+n-1);
                for (int z=0; z<n; z++)
                    cout  << items[z] << " ";
                cout << '\n';

        
    }
    return 0;
}


// Quick Sort:
int quick_sort(int *items, const int n) {
//    quickSort(items, 0 , n-1);
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
    //    for (int z=0; z<n; z++)
    //        cout << items[z] << "\n";
    //    cout << '\n';// test output
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
        
        //        for (int z=0; z<(right-left+1); z++)
//            cout << left[z] << " ";
//        cout << '\n'<<"pivot is "<< *pivot << '\n';
    }
    return pivot;
}



// mergehelper

void reverse(int *items, int* n)
{
    int *left = items;
    int *right = n ;
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
    reverse(head, mid-1);
    reverse(mid, right);
    reverse(head, right);
}

int* search(int* head, int target, int range){
    if (range <= 10 ) {
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


