/*
948. Bag of Tokens
Medium

You have an initial power of P, an initial score of 0, and a bag of tokens where tokens[i] is the value of
the ith token (0-indexed).

Your goal is to maximize your total score by potentially playing each token in one of two ways:

* If your current power is at least tokens[i], you may play the ith token face up, losing tokens[i] power and
  gaining 1 score.
* If your current score is at least 1, you may play the ith token face down, gaining tokens[i] power and
  losing 1 score.

Each token may be played at most once and in any order. You do not have to play all the tokens.

Return the largest possible score you can achieve after playing any number of tokens.

Example 1:
Input: tokens = [100], P = 50
Output: 0
Explanation: Playing the only token in the bag is impossible because you either have too little power
or too little score.

Example 2:
Input: tokens = [100,200], P = 150
Output: 1
Explanation: Play the 0th token (100) face up, your power becomes 50 and score becomes 1.
There is no need to play the 1st token since you cannot play it face up to add to your score.

Example 3:
Input: tokens = [100,200,300,400], P = 200
Output: 2
Explanation: Play the tokens in this order to get a score of 2:
1. Play the 0th token (100) face up, your power becomes 100 and score becomes 1.
2. Play the 3rd token (400) face down, your power becomes 500 and score becomes 0.
3. Play the 1st token (200) face up, your power becomes 300 and score becomes 1.
4. Play the 2nd token (300) face up, your power becomes 0 and score becomes 2.

Constraints:
0 <= tokens.length <= 1000
0 <= tokens[i], P < 104
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
#include <regex>
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
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(begin(tokens), end(tokens));
        int i = 0, j = tokens.size() - 1, score = 0;
        bool changed = true;
        while (changed && j >= 0 && (i <= j || P >= tokens[j])) {
            changed = false;
            while (i <= j && P >= tokens[i]) {
                P -= tokens[i];
                ++score;
                ++i;
                changed = true;
            }
            if (i < j && P + tokens[j] >= tokens[i] && score >= 1) {
                P += tokens[j];
                --j;
                --score;
                changed = true;
            }
        }

        return score;
    }
};

int main() {
    Solution sol;
    vector<int> tokens;
    int P;

    // Output: 0
    tokens = {100}, P = 50;
    cout << sol.bagOfTokensScore(tokens, P) << endl;

    // Output: 1
    tokens = {100,200}, P = 150;
    cout << sol.bagOfTokensScore(tokens, P) << endl;

    // Output: 2
    tokens = {100,200,300,400}, P = 200;
    cout << sol.bagOfTokensScore(tokens, P) << endl;

    // Output: 0
    tokens = {}, P = 85;
    cout << sol.bagOfTokensScore(tokens, P) << endl;

    // Output: 0
    tokens = {58,91}, P = 50;
    cout << sol.bagOfTokensScore(tokens, P) << endl;

    // Output
    tokens = {19,57,24}, P = 97;
    cout << sol.bagOfTokensScore(tokens, P) << endl;

    return 0;
}
