/*
922. Sort Array By Parity II
Easy

Given an array A of non-negative integers, half of the integers in A are odd, and half of the integers are even.

Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] is even, i is even.

You may return any answer array that satisfies this condition.

Example 1:
Input: [4,2,5,7]
Output: [4,5,2,7]
Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.

Note:
2 <= A.length <= 20000
A.length % 2 == 0
0 <= A[i] <= 1000
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

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& num) {
        int sz = num.size();
        vector<int> even, odd;
        for (int n: num) {
            if (n % 2 == 0)
                even.push_back(n);
            else
                odd.push_back(n);
        }
        for (int i = 0, head = 0; i < sz/2; ++i) {
            num[head++] = even[i];
            num[head++] = odd[i];
        }

        return num;
    }
};

int main() {
    Solution sol;
    vector<int> num;
    
    num = {4,2,5,7};

    num = {648,831,560,986,192,424,997,829,897,843};
    
    num = sol.sortArrayByParityII(num);
    copy(begin(num), end(num), ostream_iterator<int>(cout, ", "));
    cout << endl;
    return 0;
}
