// Tyler Weimin Ouyang 2014-08-15
// cs32 pa2

#include <iostream>
#include <typeinfo>
using namespace std;


// Insertion Sort:
int insertion_sort(int *items, const int n) {

    if (n > 6 || n < 0 || items == NULL) {
        return 1;
    }
    int temp, i, j;
    for (i=0; i<n-1; i++){
        if (typeid(items[i]) != typeid(int())) {
            return 1;
        }
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
    if (n <= 6) {
        insertion_sort(items, n);
        
    }
    merge_sortRecursive(items, n/2);
    merge_sortRecursive(items + n/2, n/2);
	return 1; // TODO
}

int merge_sortRecursive(int *items, const int n){
    if (n <= 6) {
        insertion_sort(items, n);
        return 0;
    }
    if (merge_sortRecursive(items, n/2) + merge_sortRecursive(items + n/2, n/2) == 0 ) {
        int j=0, k=n/2;
        for (j=0 ; j<n/2; j++){
            if (items[j] > items[ k ]) {
                int temp = items[ k ];
                for (int i=n/2-1 ; i>=0; i--){
                    items[i+1]=items[i];
                }
                items[j]=temp;
                k++;
            }
        }
        
    }
    
    
    return 1;
}


// Quick Sort:

int quick_sort(int *items, const int n) {
	return 1; // TODO
}
