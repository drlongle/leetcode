/*
914. X of a Kind in a Deck of Cards
Easy

In a deck of cards, each card has an integer written on it.

Return true if and only if you can choose X >= 2 such that it is possible to split the entire deck into 1 or more groups of cards, where:

Each group has exactly X cards.
All the cards in each group have the same integer.

Example 1:
Input: deck = [1,2,3,4,4,3,2,1]
Output: true
Explanation: Possible partition [1,1],[2,2],[3,3],[4,4].

Example 2:
Input: deck = [1,1,1,2,2,2,3,3]
Output: false´
Explanation: No possible partition.

Example 3:
Input: deck = [1]
Output: false
Explanation: No possible partition.

Example 4:
Input: deck = [1,1]
Output: true
Explanation: Possible partition [1,1].

Example 5:
Input: deck = [1,1,2,2,2,2]
Output: true
Explanation: Possible partition [1,1],[2,2],[2,2].

Constraints:
1 <= deck.length <= 10^4
0 <= deck[i] < 10^4
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

class Solution {
public:
    int gcd(int a, int b) {
        if (!b || a == b)
            return a;
        if (b > a)
            swap(a, b);
        return gcd(b, a % b);
    }

    int gcd(vector<int>& nums) {
        int res = nums[0];
        int sz = nums.size();
        for (int i = 1; i < sz; ++i)
            res = gcd(res, nums[i]);
        return res;
    }
    
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> cnt;
        for (int card: deck)
            ++cnt[card];
        vector<int> sz;
        for (auto& [k, v]: cnt)
            sz.push_back(v);
        return gcd(sz) >= 2;
    }
};

int main() {
    Solution sol;
    vector<int> deck;

    // Output: true
    deck = {1,2,3,4,4,3,2,1};
    cout << boolalpha << sol.hasGroupsSizeX(deck) << endl;
    
    // Output: false´
    deck = {1,1,1,2,2,2,3,3};
    cout << boolalpha << sol.hasGroupsSizeX(deck) << endl;
    
    // Output: false
    deck = {1};
    cout << boolalpha << sol.hasGroupsSizeX(deck) << endl;

    // Output: true
    deck = {1,1};
    cout << boolalpha << sol.hasGroupsSizeX(deck) << endl;
    
    // Output: true
    deck = {1,1,2,2,2,2};
    cout << boolalpha << sol.hasGroupsSizeX(deck) << endl;

    return 0;
}
