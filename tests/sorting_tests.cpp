#include <ctime>
#include <cstdlib>
#include "../sorting.h"
#include "gtest/gtest.h"

bool arrays_equal(int *a1, int *a2, const int n2);

void handles_invalid_args_test(sorter_t sorter, const char *sorter_name) {
	EXPECT_NE(0, sorter((int*)0, 1)) << sorter_name << " does not handle null array properly.";
	EXPECT_NE(0, sorter((int*)1, -1)) << sorter_name << " does not handle negative length properly.";
}
TEST(insertion_sort_test, handles_invalid_arguments) {
	handles_invalid_args_test(insertion_sort, "insertion sort");
}
TEST(merge_sort_test, handles_invalid_arguments) {
	handles_invalid_args_test(merge_sort, "merge sort");
}
TEST(quick_sort_test, handles_invalid_arguments) {
	handles_invalid_args_test(quick_sort, "quick sort");
}

void sorting_correctness_test(sorter_t sorter, const char *sorter_name) {
	int a1[] = { 1 };
	int b1[] = { 1 };

	EXPECT_EQ(0, sorter(&a1[0], 1)) << "{ 1 } -- " << sorter_name << " -- failed.";
	EXPECT_TRUE(arrays_equal(&b1[0], &a1[0], 1)) << "{ 1 } -- " << sorter_name << " -- incorrectly sorted.";

	int a2[] = { 3, 1 };
	int b2[] = { 1, 3 };

	EXPECT_EQ(0, sorter(&a2[0], 2)) << "{ 3, 1 } -- " << sorter_name << " -- sorting failed.";
	EXPECT_TRUE(arrays_equal(&b2[0], &a2[0], 2)) << "{ 3, 1 } -- " << sorter_name << " -- incorrectly sorted.";

    int a3[] = { -1, 0, -2 };
    int b3[] = { -2, -1, 0 };

	EXPECT_EQ(0, sorter(&a3[0], 3)) << "{ -1, 0, -2 } -- " << sorter_name << " -- sorting failed.";
	EXPECT_TRUE(arrays_equal(&b3[0], &a3[0], 3)) << "{ -1, 0, -2} -- " << sorter_name << " incorrectly sorted.";

	int a4[] = { 10, 5, 1, 4, 5, 7, 2, 3, 6, 8, 9, 5 };
    int b4[] = { 1, 2, 3, 4, 5, 5, 5, 6, 7, 8, 9, 10 };

	EXPECT_EQ(0, sorter(&a4[0], 12)) << "{ 10, 5, 1, 4, 5, 7, 2, 3, 6, 8, 9, 5 } -- " << sorter_name << " sorting failed.";
	EXPECT_TRUE(arrays_equal(&b4[0], &a4[0], 12)) << "{ 10, 5, 1, 4, 5, 7, 2, 3, 6, 8, 9, 5 } -- " << sorter_name << " incorrectly sorted.";
}
TEST(insertion_sort_test, sorting_correctness) {
	sorting_correctness_test(insertion_sort, "insertion sort");
}
TEST(merge_sort_test, sorting_correctness) {
	sorting_correctness_test(merge_sort, "merge sort");
}
TEST(quick_sort_test, sorting_correctness) {
	sorting_correctness_test(quick_sort, "quick sort");
}


int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
