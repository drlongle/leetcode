/*
418. Sentence Screen Fitting

    User Accepted: 132
    User Tried: 302
    Total Accepted: 136
    Total Submissions: 1082
    Difficulty: Hard

Given a rows x cols screen and a sentence represented by a list of words,
find how many times the given sentence can be fitted on the screen.

Note:
    A word cannot be split into two lines.
    The order of words in the sentence must remain unchanged.
    Two consecutive words in a line must be separated by a single space.
    Total words in the sentence won't exceed 100.
    Length of each word won't exceed 10.
    1 <= rows, cols <= 20,000.

Example 1:

Input:
rows = 2, cols = 8, sentence = ["hello", "world"]

Output:
1

Explanation:
hello---
world---

The character '-' signifies an empty space on the screen.

Example 2:

Input:
rows = 3, cols = 6, sentence = ["a", "bcd", "e"]

Output:
2

Explanation:
a-bcd-
e-a---
bcd-e-

The character '-' signifies an empty space on the screen.

Example 3:

Input:
rows = 4, cols = 5, sentence = ["I", "had", "apple", "pie"]

Output:
1

Explanation:
I-had
apple
pie-I
had--

The character '-' signifies an empty space on the screen.
 */

#include <algorithm>
#include <array>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>

#define ll long long int
#define ull unsigned long long int

using namespace std;

class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int res = 0;
        int blank = cols;
        int index = 0, cnt = 1;
        int sentence_size = sentence.size();
        vector<vector<pair<int, int>>> dp(sentence_size, vector<pair<int, int>>(cols+1));
        while (rows >= cnt)
        {
            int word_size = sentence[index].size();
            if (word_size > cols)
                return 0;
            auto& cell = dp[index][blank];
            if (cell.second > 0) {
                int diff = cnt - cell.second;
                if (diff > 0) {
                    int div = (rows - cnt - 1) / diff;
                    res += (res - cell.first) * div;
                    cnt += diff * div;
                }
            } else
                cell = make_pair(res, cnt);
            if (blank >= word_size)
                blank -= word_size;
            else {
                if (rows == cnt)
                    break;
                ++cnt;
                blank = cols - word_size;
            }
            if (blank > 0)
                --blank;
            if (index == sentence_size - 1)
            {
                ++res;
                index = 0;
                if (blank == 0) {
                    int div = rows / cnt;
                    res *= div;
                    cnt *= div;
                }
            }
            else
                ++index;
        }

        return res;
    }
};

int main()
{
    Solution sol;
    int rows, cols, res;
    vector<string> sentence;

    // Expected: 1
    rows = 2, cols = 8, sentence = {"hello", "world"};
    cout << "Result: " << sol.wordsTyping(sentence, rows, cols) << endl;

    // Expected: 2
    rows = 3, cols = 6, sentence = {"a", "bcd", "e"};
    cout << "Result: " << sol.wordsTyping(sentence, rows, cols) << endl;

    // Expected: 1
    rows = 4, cols = 5, sentence = {"I", "had", "apple", "pie"};
    cout << "Result: " << sol.wordsTyping(sentence, rows, cols) << endl;

    // Expected: 10
    rows = 8, cols = 7, sentence = {"f","p","a"};
    cout << "Result: " << sol.wordsTyping(sentence, rows, cols) << endl;

    res = sol.wordsTyping(sentence, rows, cols);
    cout << "Result: " << res << endl;

    sentence = {"hello"}, rows = 10000, cols = 1;
    cout << "Result: " << sol.wordsTyping(sentence, rows, cols) << endl;

    sentence = {"a","b","e"}, rows = 20000, cols = 20000;
    cout << "Result: " << sol.wordsTyping(sentence, rows, cols) << endl;

    sentence = {"try","to","be","better"}, rows = 10000, cols = 9001;
    cout << "Result: " << sol.wordsTyping(sentence, rows, cols) << endl;

    return 0;
}

