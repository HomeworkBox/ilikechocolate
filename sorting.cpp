// Tyler Weimin Ouyang 2014-08-15
// cs32 pa2

#include <iostream>
#include <typeinfo>
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
    if (n <= 6) {
        insertion_sort(items, n);
        
    }
    int j,k, temp,nn;
    if (n%2 != 0) {
        if (merge_sortRecursive(items, n/2) + merge_sortRecursive(items + n/2, n/2+1) == 0 ) {
            j=0, k=n/2,nn=n-1;
            for (j=0 ; j<nn; j++){ //  there is also a problem with j's boundary. It was j < n/2-1
                if (items[j] >= items[ k ]) {
                    temp = items[ k ];
                    for (int i=k-1 ; i>=j; i--){ //i should not equal to n/2-1, which is fixed; i should stop at j
                        items[i+1]=items[i];
                    }
                    items[j]=temp;
                    if (k<nn) // before k could go out of the range
                        k++;
                }
            }
            
        }
        return 0;
        
    }
    else{
        if (merge_sortRecursive(items, n/2) + merge_sortRecursive(items + n/2, n/2) == 0 ) {
            j=0, k=n/2, nn=n-1;
            for (j=0 ; j<nn; j++){ //  there is also a problem with j's boundary. It was j < n/2-1
                if (items[j] >= items[ k ]) {
                    temp = items[ k ];
                    for (int i=k-1 ; i>=j; i--){ //i should not equal to n/2-1, which is fixed; i should stop at j
                        items[i+1]=items[i];
                    }
                    items[j]=temp;
                    if (k<nn) // before k could go out of the range
                        k++;
                    //                for (int z=0; z<n; z++)
                    //                    cout << items[z] << " ";
                    //                cout << '\n';// test output
                }
            }
            
        }
        return 0;
    }
    
	return 1;
}

int merge_sortRecursive(int *items, const int n){
    if (n <= 6) {
        insertion_sort(items, n);
        //        for (int z=0; z<n; z++)
        //            cout << items[z] << " ";
        //        cout << '\n';
        return 0;
    }
    int j,k,temp,nn;
    if (n%2 != 0) {
        if (merge_sortRecursive(items, n/2) + merge_sortRecursive(items + n/2, n/2+1) == 0 ) {
            //cout << n<< '\n';
            j=0, k=n/2,nn=n-1;
            for (j=0 ; j<nn; j++){ //  there is also a problem with j's boundary. It was j < n/2-1
                if (items[j] >= items[ k ]) {
                    temp = items[ k ];
                    for (int i=k-1 ; i>=j; i--){ //i should not equal to n/2-1, which is fixed; i should stop at j
                        items[i+1]=items[i];
                    }
                    items[j]=temp;
                    if (k<nn) // before k could go out of the range
                        k++;
                    
                }
            }
            
        }
        return 0;
        
    }
    else{
        if (merge_sortRecursive(items, n/2) + merge_sortRecursive(items + n/2, n/2) == 0 ) {
            //cout << n<< '\n';
            j=0, k=n/2;
            for (j=0 ; j<nn; j++){ //  there is also a problem with j's boundary. It was j < n/2-1
                if (items[j] >= items[ k ]) {
                    temp = items[ k ];
                    for (int i=k-1 ; i>=j; i--){ //i should not equal to n/2-1, which is fixed; i should stop at j
                        items[i+1]=items[i];
                    }
                    items[j]=temp;
                    if (k<nn) // before k could go out of the range
                        k++;
                    //                for (int z=0; z<n; z++)
                    //                    cout << items[z] << " ";
                    //                cout << '\n';// test output
                }
            }
            
        }
        return 0;
    }
    
    
    return 1;
}


// Quick Sort:

int quick_sort(int *items, const int n) {
	return 1; // TODO
}
