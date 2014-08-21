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
	return 1; // TODO
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
//        while (jptr < kptr) {
//            if (*jptr >= *kptr) {
//                int temp = *kptr;
//                for (int* i=kptr-1; i>=jptr; i--) {
//                    *(i+1) = *i;
//                }
//                *jptr = temp;
//                for (int z=0; z<n; z++)
//                    cout << items[z] << " ";
//                cout << '\n';
//            }
//            jptr++;
//        }
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
