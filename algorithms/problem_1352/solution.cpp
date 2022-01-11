/*
1352. Product of the Last K Numbers
Medium

Implement the class ProductOfNumbers that supports two methods:

1. add(int num)
Adds the number num to the back of the current list of numbers.

2. getProduct(int k)
Returns the product of the last k numbers in the current list.
You can assume that always the current list has at least k numbers.
At any time, the product of any contiguous sequence of numbers
will fit into a single 32-bit integer without overflowing.

Example:
Input
["ProductOfNumbers","add","add","add","add","add","getProduct","getProduct","getProduct","add","getProduct"]
[[],[3],[0],[2],[5],[4],[2],[3],[4],[8],[2]]

Output
[null,null,null,null,null,null,20,40,0,null,32]

Explanation
ProductOfNumbers productOfNumbers = new ProductOfNumbers();
productOfNumbers.add(3);        // [3]
productOfNumbers.add(0);        // [3,0]
productOfNumbers.add(2);        // [3,0,2]
productOfNumbers.add(5);        // [3,0,2,5]
productOfNumbers.add(4);        // [3,0,2,5,4]
productOfNumbers.getProduct(2); // return 20. The product of the last 2 numbers is 5 * 4 = 20
productOfNumbers.getProduct(3); // return 40. The product of the last 3 numbers is 2 * 5 * 4 = 40
productOfNumbers.getProduct(4); // return 0. The product of the last 4 numbers is 0 * 2 * 5 * 4 = 0
productOfNumbers.add(8);        // [3,0,2,5,4,8]
productOfNumbers.getProduct(2); // return 32. The product of the last 2 numbers is 4 * 8 = 32 

Constraints:
There will be at most 40000 operations considering both add and getProduct.
0 <= num <= 100
1 <= k <= 40000
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class ProductOfNumbers {
public:
    
    ProductOfNumbers(): prods{1}, index(0) {}
    static constexpr int Segment_Size = 100;
    void add(int num) {
        nums.emplace_back(num);
        prods.back() *= num;
        if (++index >= Segment_Size) {
            index = 0;
            prods.emplace_back(1);
        }
    }

    int getProduct(int begin, int end) {
        int seg_index = begin / Segment_Size;
        if ((begin == seg_index * Segment_Size) && (end + 1 == (seg_index+1) * Segment_Size))
            return prods[seg_index];
        auto lambda = [](int a, int b) {return a*b;};
        return accumulate(nums.begin() + begin, nums.begin() + end+1, 1, lambda);
    }
    
    int getProduct(int k) {
        int res = 1;
        int end = nums.size()-1;
        int begin = end - k + 1;
        for (int seg_index = begin / Segment_Size; seg_index <= end / Segment_Size; ++seg_index) {
            res *= getProduct(max(begin, seg_index*Segment_Size), min(end, seg_index*Segment_Size + Segment_Size-1));
        }

        return res;
    }

    vector<int> prods, nums;
    int index;
};

void test_0() {
    ProductOfNumbers productOfNumbers;
    int res;
    productOfNumbers.add(3);        // [3]
    productOfNumbers.add(0);        // [3,0]
    productOfNumbers.add(2);        // [3,0,2]
    productOfNumbers.add(5);        // [3,0,2,5]
    productOfNumbers.add(4);        // [3,0,2,5,4]
    res = productOfNumbers.getProduct(2); // return 20. The product of the last 2 numbers is 5 * 4 = 20
    cout << res << endl;
    res = productOfNumbers.getProduct(3); // return 40. The product of the last 3 numbers is 2 * 5 * 4 = 40
    cout << res << endl;
    res = productOfNumbers.getProduct(4); // return 0. The product of the last 4 numbers is 0 * 2 * 5 * 4 = 0
    cout << res << endl;
    productOfNumbers.add(8);        // [3,0,2,5,4,8]
    res = productOfNumbers.getProduct(2); // return 32. The product of the last 2 numbers is 4 * 8 = 32
    cout << res << endl;
}

int main() {
    test_0();
    return 0;
}
