#include "SegmentTree.h"

#include <iostream>
#include <numeric>

void test1() {
    std::vector<int> arr{1, 3, 5, 7, 9, 11};

    // Build segment tree from given array
    SegmentTree st(arr);

    // Print sum of values in array from index 1 to 3
    std::cout << "Sum of values in given range = " << st.getSum(1, 3)
              << std::endl;

    // Update: set arr[1] = 10 and update corresponding
    // segment tree nodes
    st.updateValue(1, 10);

    // Find sum after the value is updated
    std::cout << "Updated sum of values in given range = " << st.getSum(1, 3)
              << std::endl;
}

void test2() {
    std::vector<int> arr(10);
    std::iota(std::begin(arr), std::end(arr), 1);

    // Build segment tree from given array
    SegmentTree st(arr);

    // Print sum of values in array from index 1 to 3
    std::cout << "Sum of values in given range = " << st.getSum(1, 3)
              << std::endl;

    // Update: set arr[1] = 10 and update corresponding
    // segment tree nodes
    st.updateValue(1, 10);

    // Find sum after the value is updated
    std::cout << "Updated sum of values in given range = " << st.getSum(1, 3)
              << std::endl;
}

int main() {
    test1();
    test2();

    return 0;
}
