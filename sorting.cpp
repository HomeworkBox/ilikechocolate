// Tyler Weimin Ouyang 2014-08-15
// cs32 pa2

// Insertion Sort:

int insertion_sort(int *items, const int n) {
    int temp, i, j;
    for (i=0; i<n-1; i++){
        if (items[i] > items[i+1]) {
            temp = items[i+1];
            for (j=i; j>=0; j--){
                if(items[j] > temp){
                    //int temp = item[i];
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
