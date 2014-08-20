#include <ctime>
#include <cstdlib>
#include "../sorting.h"
#include "gtest/gtest.h"

bool arrays_equal(int *a1, int *a2, const int n2);
void shuffle(int *vals, const int n, const unsigned int seed);

void sorting_performance_test(sorter_t sorter, const char *sorter_name, const int n, const double max_time_sec) {
	int *data = new int[n];
	int *copy = new int[n];
	for(int i = 0; i < n; i++) {
		data[i] = i + 1;
		copy[i] = data[i];
        
        //std::cout << copy[i]<<'\n';
        
    }
	
 	const unsigned int seed = 2128506;
	shuffle(data, n, seed);

	time_t t1 = clock();
	int exit_code = sorter(data, n);
	time_t t2 = clock();
	double sorting_time_sec = double(t2 - t1) / CLOCKS_PER_SEC;

	ASSERT_EQ(0, exit_code) << "{ array of " << n << " ints } -- " << sorter_name << " sorting failed.";
	ASSERT_TRUE(arrays_equal(copy, data, n)) << "{ array of " << n << " ints } -- " << sorter_name << " sorting failed.";
	EXPECT_GT(max_time_sec, sorting_time_sec) << "{ array of " << n << " ints } -- " << sorter_name << " sorting is too slow "
		<< "(it takes " << sorting_time_sec << "sec, while the expected max is " << max_time_sec << "sec.";

	delete [] data;
	delete [] copy;
}

TEST(insertion_sort_test, sorting_performance) {
	sorting_performance_test(insertion_sort, "insertion sort", 50000, 2);
}
TEST(merge_sort_test, sorting_performance) {
    sorting_performance_test(merge_sort, "merge sort", 4*10e+4, 4);
}
TEST(quick_sort_test, sorting_performance) {
	sorting_performance_test(quick_sort, "quick sort", 10e+6, 3);
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
