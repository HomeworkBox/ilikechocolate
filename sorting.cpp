// Tyler Weimin Ouyang 2014-08-15
// cs32 pa2

#include <array>
using namespace std;


// Insertion Sort:
int insertion_sort(int *items, const int n) {
//    printf("size of items is %lu, and size of items[1] is %lu", sizeof items,sizeof items[1] );
    if (n > 6) {
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
	return 1; // TODO
}

// Quick Sort:

int quick_sort(int *items, const int n) {
	return 1; // TODO
}
