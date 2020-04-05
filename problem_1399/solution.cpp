/*
1399. Count Largest Group
Easy

Given an integer n. Each number from 1 to n is grouped according to the sum of its digits. 

Return how many groups have the largest size.

Example 1:
Input: n = 13
Output: 4
Explanation: There are 9 groups in total, they are grouped according sum of its digits of numbers from 1 to 13:
[1,10], [2,11], [3,12], [4,13], [5], [6], [7], [8], [9]. There are 4 groups with largest size.

Example 2:
Input: n = 2
Output: 2
Explanation: There are 2 groups [1], [2] of size 1.

Example 3:
Input: n = 15
Output: 6

Example 4:
Input: n = 24
Output: 5

Constraints:
1 <= n <= 10^4
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
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
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class Solution {
public:
    int get_sum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        unordered_map<int, int> cnt;
        for (int i = 1; i <= n; ++i)
            ++cnt[get_sum(i)];
        auto it = max_element(begin(cnt), end(cnt), [&] (auto& p1, auto&p2) { return p1.second < p2.second;});
        
        return count_if(begin(cnt), end(cnt), [&] (auto& p) {return p.second == it->second;});
    }
};

int main() {
    Solution sol;
    int n;

    n = 12;
    cout << n << " -> " << sol.countLargestGroup(n) << endl;

    n = 13;
    cout << n << " -> " << sol.countLargestGroup(n) << endl;

    n = 15;
    cout << n << " -> " << sol.countLargestGroup(n) << endl;
    
    return 0;
}
