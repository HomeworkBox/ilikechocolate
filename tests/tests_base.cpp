#include <ctime>
#include <cstdlib>
#include "../sorting.h"

void shuffle(int *vals, const int n, const unsigned int seed) {
	srand(seed);
	for(int i = 0; i < n; i++) {
		int j = rand() % n;
		int temp = vals[i];
		vals[i] = vals[j];
		vals[j] = temp;
	}
}

bool arrays_equal(int *a1, int *a2, const int n) {
	if(!a1 && !a2 || n == 0)
		return true;
	else if(a1 && !a2 || !a1 && a2 || n < 0)
		return false;
	else {
		for(int i = 0; i < n; i++) {
			if(a1[i] != a2[i])
				return false;
		}
		return true;
	}
}
