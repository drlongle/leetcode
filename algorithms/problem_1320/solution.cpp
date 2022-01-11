/*
1320. Minimum Distance to Type a Word Using Two Fingers
Hard

You have a keyboard layout as shown above in the XY plane, where each English uppercase letter is located at some coordinate, for example, the letter A is located at coordinate (0,0), the letter B is located at coordinate (0,1), the letter P is located at coordinate (2,3) and the letter Z is located at coordinate (4,1).

Given the string word, return the minimum total distance to type such string using only two fingers. The distance between coordinates (x1,y1) and (x2,y2) is |x1 - x2| + |y1 - y2|. 

Note that the initial positions of your two fingers are considered free so don't count towards your total distance, also your two fingers do not have to start at the first letter or the first two letters.

Example 1:
Input: word = "CAKE"
Output: 3
Explanation: 
Using two fingers, one optimal way to type "CAKE" is: 
Finger 1 on letter 'C' -> cost = 0 
Finger 1 on letter 'A' -> cost = Distance from letter 'C' to letter 'A' = 2 
Finger 2 on letter 'K' -> cost = 0 
Finger 2 on letter 'E' -> cost = Distance from letter 'K' to letter 'E' = 1 
Total distance = 3

Example 2:
Input: word = "HAPPY"
Output: 6
Explanation: 
Using two fingers, one optimal way to type "HAPPY" is:
Finger 1 on letter 'H' -> cost = 0
Finger 1 on letter 'A' -> cost = Distance from letter 'H' to letter 'A' = 2
Finger 2 on letter 'P' -> cost = 0
Finger 2 on letter 'P' -> cost = Distance from letter 'P' to letter 'P' = 0
Finger 1 on letter 'Y' -> cost = Distance from letter 'A' to letter 'Y' = 4
Total distance = 6

Example 3:
Input: word = "NEW"
Output: 3

Example 4:
Input: word = "YEAR"
Output: 7

Constraints:
2 <= word.length <= 300
Each word[i] is an English uppercase letter.
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

namespace std {
    template <> struct hash<vector<int>> {
        size_t operator()(const vector<int>& v) const {
            size_t res = 0;
            for (auto& elem: v)
                res ^= elem;
            return res;
        }
    };
}

class Solution {
public:
    static constexpr int board_size = 6;
    vector<int> get_pos(char ch) {
        int offset = ch - 'A';
        return {offset / board_size, offset % board_size};
    }
    
    int distance(const vector<int>& pos1, const vector<int>& pos2) {
        return abs(pos1[0] - pos2[0]) + abs(pos1[1] - pos2[1]);
    }

    int minimumDistance(string word) {
        int sz = word.size();
        unordered_map<vector<int>, int> dp;
        vector<int> key = get_pos(word[0]);
        key.push_back(-1);
        key.push_back(-1);
        dp[key] = 0;
        for (int i = 1; i < sz; ++i) {
            vector<int> pos = get_pos(word[i]);
            unordered_map<vector<int>, int> new_dp;
            for (auto& p: dp) {
                
                // Move first finger
                vector<int> key{pos[0], pos[1], p.first[2], p.first[3]};
                int cost = p.second + distance(pos, {p.first[0], p.first[1]});
                auto it = new_dp.find(key);
                if (it == new_dp.end())
                    new_dp[key] = cost;
                else
                    it->second = min(it->second, cost);
                
                // Move second finger
                key = vector<int>{p.first[0], p.first[1], pos[0], pos[1]};
                cost = p.second + ((p.first[2] >= 0) ? distance(pos, {p.first[2], p.first[3]}) : 0);
                it = new_dp.find(key);
                if (it == new_dp.end())
                    new_dp[key] = cost;
                else
                    it->second = min(it->second, cost);
            }
            dp = std::move(new_dp);
        }
        auto lambda = [] (auto& p1, auto&p2) {return p1.second < p2.second;};
        auto it = min_element(begin(dp), end(dp), lambda);
        return it->second;
    }
};

int main() {
    Solution sol;
    string word;
    
    // Output: 3
    word = "CAKE";

    // Output: 6
    //word = "HAPPY";

    // Output: 3
    //word = "NEW";

    // Output: 7
    //word = "YEAR";

    cout << "Result: " << sol.minimumDistance(word) << endl;
        
    return 0;
}
