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
        int index = 0;
        int sentence_size = sentence.size();
        while (rows > 0)
        {
            int word_size = sentence[index].size();
            if (blank >= word_size)
                blank -= word_size;
            else
            {
                if (rows == 1)
                    break;
                --rows;
                blank = cols - word_size;
            }
            if (blank > 0)
                --blank;
            //cout << sentence[index] << ", rows: " << rows << ", blank: " << blank << endl;
            if (index == sentence_size - 1)
            {
                ++res;
                index = 0;
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

    // Expected: 2
    rows = 3, cols = 6, sentence = {"a", "bcd", "e"};

    // Expected: 1
    //rows = 4, cols = 5, sentence = {"I", "had", "apple", "pie"};

    // Expected: 10
    rows = 8, cols = 7, sentence = {"f","p","a"};

    res = sol.wordsTyping(sentence, rows, cols);
    cout << "Result: " << res << endl;

    return 0;
}

