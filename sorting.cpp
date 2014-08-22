// Tyler Weimin Ouyang 2014-08-15
// cs32 pa2

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
        //        if (typeid(items[i]) != typeid(int())) {
        //            return 1;
        //        }
        if (items[i] > items[i+1]) {
            temp = items[i+1];
            for (j=i; j>=0; j--){
                if(items[j] > temp){
                    items[j+1]=items[j];
                    items[j]=temp;
                }
            }
        }
    }
    return 0;
}

// Merge Sort:

int merge_sort(int *items, const int n) {
    if (n < 0 || items == NULL) {
        return 1;
    }
    else if (n <= 6) {
        insertion_sort(items, n);
    }
    else if (n%2 != 0) {
        merge_sortRecursive(items, n/2+1);
        merge_sortRecursive(items + n/2+1, n/2);
        merge (items, n, n/2+1);
    }
    else {
        merge_sortRecursive(items, n/2);
        merge_sortRecursive(items + n/2, n/2);
        merge (items, n, n/2);

    }
//    for (int z=0; z<n; z++)
//        cout << items[z] << "\n";
//    cout << '\n';// test output
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
        
        merge (items, n, n/2+1);
//        for (int z=0; z<n; z++)
//            cout << items[z] << " ";
//        cout << '\n';

    }
    else {
        merge_sortRecursive(items, n/2);
        merge_sortRecursive(items + n/2, n/2);

        merge (items, n, n/2);
//                for (int z=0; z<n; z++)
//                    cout << items[z] << " ";
//                cout << '\n';

        
    }
    return 0;
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
    //int *l=left, *r=right;
    int temp1=0,temp2=0, *lp=left, *rp=right;
    do {
        int judge1=0, judge2=0;
        while (lp < pivot) {
            if (*lp >= *pivot){
                temp1 = *lp;
                judge1 = 1;
                break;
            }
            lp++;
        }
        while (rp > pivot) {
            if (*rp < *pivot){
                temp2 = *rp;
                judge2 = 2;
                break;
            }
            rp--;
        }
        if (judge1+judge2==3) {
            *lp = *rp;
            *rp = temp1;
       
        }
        else if(judge1+judge2==1){
            *lp = *pivot;
            *pivot = temp1;
            pivot = lp;
        }
        else if(judge1+judge2==2){
            *rp = *pivot;
            *pivot = temp2;
            pivot = rp;
        }
        else
            break;
//        for (int z=0; z<(right-left+1); z++)
//            cout << left[z] << " ";
//        cout << '\n'<<"pivot is "<< *pivot << '\n';
    } while (pivot!=lp || pivot!=rp);
    return pivot;
}



// mergehelper
int merge(int *items, const int n, int k){
    
    if (items[k]>= items[k-1]) {
        return 0;
    }
    else if (items[n-1] <= items [0] ) {
        exchange(&items[0], &items[k], &items[n-1]);
        return 0;
    }
    
    else{
        //cout << n<< '\n';
        int *kptr=&items[k], *jptr=&items[0];
        while (kptr < items + n) {
            
            int *locationA = search(jptr, *kptr, kptr - jptr);
            int *locationB = search(kptr, *locationA, n-k)-1;
//            cout << '\n'<< "location a "<< locationA-items<<" ;locationB "<< locationB-items<<"\n";

            if (locationB <= locationA)
                break;
                        exchange( locationA, kptr, locationB);
            jptr = jptr - kptr + locationB +1;
            k+= locationB +1 - kptr;
            kptr = locationB+1;
            
//            for (int z=0; z<n; z++)
//                cout << items[z] << " ";
            
        }
    }
    
    return 0;
}

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
