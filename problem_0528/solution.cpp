/*
528. Random Pick with Weight
Medium

Given an array w of positive integers, where w[i] describes the weight of index i, write a function pickIndex which randomly picks an index in proportion to its weight.

Note:
1 <= w.length <= 10000
1 <= w[i] <= 10^5
pickIndex will be called at most 10000 times.

Example 1:
Input: 
["Solution","pickIndex"]
[[[1]],[]]
Output: [null,0]

Example 2:
Input: 
["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
[[[1,3]],[],[],[],[],[]]
Output: [null,0,1,1,1,0]

Explanation of Input Syntax:
The input is two lists: the subroutines called and their arguments. Solution's constructor has one argument, the array w. pickIndex has no arguments. Arguments are always wrapped with a list, even if there aren't any.
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
    Solution(vector<int>& weights) {
        max_value = 0;
        for (int index = 0; auto weight: weights) {
            max_value += weight;
            lookup[max_value] = index++;
        }
    }

    map<int, int> lookup;
    int max_value;
    
    int pickIndex() {
        std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_int_distribution<int> distribution(1, max_value);
        int index = distribution(generator);
        auto it = lookup.lower_bound(index);
        return it->second;
    }
};

void test1()
{
    vector<int> weights({3, 14, 1, 7});
    Solution sol(weights);
    map<int, int> counters;
    int num = 10000;
    for (int i = 0; i < num; ++i) {
        int index = sol.pickIndex();
        ++counters[index];
    }
    for (auto& [index, value]: counters) {
        cout << index << " -> " << static_cast<double>(value) / num << endl;
    }
}

int main() {
    test1();
}
