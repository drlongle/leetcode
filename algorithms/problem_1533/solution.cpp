/*
1533. Find the Index of the Large Integer
Medium

We have an integer array arr, where all the integers in arr are equal except for
one integer which is larger than the rest of the integers. You will not be given
direct access to the array, instead, you will have an API ArrayReader which have
the following functions:

int compareSub(int l, int r, int x, int y): where 0 <= l, r, x, y <
ArrayReader.length(), l <= r and x <= y. The function compares the sum of
sub-array arr[l..r] with the sum of the sub-array arr[x..y] and returns: 1 if
arr[l]+arr[l+1]+...+arr[r] > arr[x]+arr[x+1]+...+arr[y]. 0 if
arr[l]+arr[l+1]+...+arr[r] == arr[x]+arr[x+1]+...+arr[y]. -1 if
arr[l]+arr[l+1]+...+arr[r] < arr[x]+arr[x+1]+...+arr[y]. int length(): Returns
the size of the array. You are allowed to call compareSub() 20 times at most.
You can assume both functions work in O(1) time.

Return the index of the array arr which has the largest integer.

Example 1:
Input: arr = [7,7,7,7,10,7,7,7]
Output: 4
Explanation: The following calls to the API
reader.compareSub(0, 0, 1, 1) // returns 0 this is a query comparing the
sub-array (0, 0) with the sub array (1, 1), (i.e. compares arr[0] with arr[1]).
Thus we know that arr[0] and arr[1] doesn't contain the largest element.
reader.compareSub(2, 2, 3, 3) // returns 0, we can exclude arr[2] and arr[3].
reader.compareSub(4, 4, 5, 5) // returns 1, thus for sure arr[4] is the largest
element in the array. Notice that we made only 3 calls, so the answer is valid.

Example 2:
Input: nums = [6,6,12]
Output: 2

Constraints:
2 <= arr.length <= 5 * 105
1 <= arr[i] <= 100
All elements of arr are equal except for one element which is larger than all
other elements.

Follow up:
What if there are two numbers in arr that are bigger than all other numbers?
What if there is one number that is bigger than other numbers and one number
that is smaller than other numbers?
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <ranges>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "common/FenwickTree.h"
#include "common/ListNode.h"
#include "common/Node.h"
#include "common/SegmentTree.h"
#include "common/TreeNode.h"
#include "common/UnionFind.h"
#include "common/bits.h"

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

class ArrayReader {
  public:
    // Compares the sum of arr[l..r] with the sum of arr[x..y]
    // return 1 if sum(arr[l..r]) > sum(arr[x..y])
    // return 0 if sum(arr[l..r]) == sum(arr[x..y])
    // return -1 if sum(arr[l..r]) < sum(arr[x..y])
    int compareSub(int l, int r, int x, int y) { return 0; }

    // Returns the length of the array
    int length() { return 0; }
};

class Solution {
  public:
    int getIndex(ArrayReader &reader) {
        int left = 0, right = reader.length() - 1;

        while (left < right) {
            int n = right - left + 1;
            int left_end = left + n / 2 - 1;
            int right_end = right - n / 2 + 1;
            int r = reader.compareSub(left, left_end, right_end, right);
            if (r < 0)
                left = left_end + 1;
            else if (r == 0)
                return left_end + 1;
            else
                right = right_end - 1;
        }

        return left;
    }
};

int main() { return 0; }
