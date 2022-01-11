/*
846. Hand of Straights
Medium

Alice has a hand of cards, given as an array of integers.
Now she wants to rearrange the cards into groups so that each group is size W, and consists of W consecutive cards.
Return true if and only if she can.

Example 1:
Input: hand = [1,2,3,6,2,3,4,7,8], W = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8].

Example 2:
Input: hand = [1,2,3,4,5], W = 4
Output: false
Explanation: Alice's hand can't be rearranged into groups of 4.

Constraints:
1 <= hand.length <= 10000
0 <= hand[i] <= 10^9
1 <= W <= hand.length
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
    bool isNStraightHand(vector<int>& hand, int W) {
        map<int, int> cnts;
        for (int h: hand)
            ++cnts[h];
        while (!cnts.empty()) {
            int start = cnts.begin()->first;
            int num = cnts.begin()->second;
            for (int i = 0; i < W; ++i) {
                int val = start + i;
                if (cnts[val] < num)
                    return false;
                cnts[val] -= num;
                if (cnts[val] == 0)
                    cnts.erase(val);
            }
        }

        return true;
    }
};

int main() {
    Solution sol;
    vector<int> hand;
    int W;

    hand = {1,2,3,6,2,3,4,7,8}, W = 3;
    cout << boolalpha << sol.isNStraightHand(hand, W) << endl;

    hand = {1,2,3,4,5}, W = 4;
    cout << boolalpha << sol.isNStraightHand(hand, W) << endl;
    
    return 0;
}
