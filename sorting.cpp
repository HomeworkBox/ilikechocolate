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

int merge_sortRecursive(int *items, const int n){
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
    
    int j=0,temp, head;
    
    if (items[k]>= items[k-1]) {
        return 0;
    }
    else if (items[n-1] <= items [0] ) {
        if (n%2 == 0) {
            
            for (j=0; j<n/2; j++,k++) {
                temp = items[k];
                items[k]=items[j];
                items[j]=temp;
            }
        }
        else {
            temp=items[k-1];
            for (j=0; j<n/2; j++,k++) {
                items[k-1]=items[j];
                items[j]=items[k];
            }
            items[n-1]=temp;
        }
        
        return 0;
    }
    
    else{
        //cout << n<< '\n';
        
        while (j<k && k < n) {
            if (items[j] > items[ k ]) {
                head = k;
                while (items[k] <= items [j] && k<n) {
                    k++;
                }
                exchange(&items[j], head-j, k-head);
                j= j- head + k;
//                for (int z=0; z<n; z++)
//                    cout << items[z] << " ";
//                cout << '\n';
            }
            j++;
        }
        
    }
    
    
    return 0;
}

void reverse(int *items, int n)
{
    int left = 0;
    int right = n -1;
    while(left < right)
    {
        int temp = items[left];
        items[left++] = items[right];
        items[right--] = temp;
    }
}

void exchange(int *head, int left, int right){
    reverse(head, left);
    reverse(head+left, right);
    reverse(head, left+right);
}
