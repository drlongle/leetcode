/*
1255. Maximum Score Words Formed by Letters
Hard

Given a list of words, list of single letters (might be repeating) and score of every character.

Return the maximum score of any valid set of words formed by using the given letters
(words[i] cannot be used two or more times).

It is not necessary to use all characters in letters and each letter can only be used once.
Score of letters 'a', 'b', 'c', ... ,'z' is given by score[0], score[1], ... , score[25] respectively.

Example 1:
Input:
words = ["dog","cat","dad","good"],
letters = ["a","a","c","d","d","d","g","o","o"],
score = [1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0]
Output: 23
Explanation:
Score  a=1, c=9, d=5, g=3, o=2
Given letters, we can form the words "dad" (5+1+5) and "good" (3+2+2+5) with a score of 23.
Words "dad" and "dog" only get a score of 21.

Example 2:
Input:
words = ["xxxz","ax","bx","cx"],
letters = ["z","a","b","c","x","x","x"],
score = [4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,10]
Output: 27
Explanation:
Score  a=4, b=4, c=4, x=5, z=10
Given letters, we can form the words "ax" (4+5), "bx" (4+5) and "cx" (4+5) with a score of 27.
Word "xxxz" only get a score of 25.

Example 3:
Input:
words = ["leetcode"],
letters = ["l","e","t","c","o","d"],
score = [0,0,1,1,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0]
Output: 0
Explanation:
Letter "e" can only be used once.
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
    int get_score(vector<string>& words, vector<int>& score, map<char, int> counts, int pos) {
        if (pos == words.size())
            return 0;
        int res = get_score(words, score, counts, pos+1);
        int r = 0;
        bool valid = true;
        for (char ch: words[pos]) {
            if (counts[ch]-- == 0) {
                valid = false;
                r = 0;
                break;
            }
            r += score[ch-'a'];
        }
        if (valid)
            r += get_score(words, score, counts, pos+1);

        return max(r, res);
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        map<char, int> counts;
        for (char ch: letters)
            ++counts[ch];
        return get_score(words, score, counts, 0);
    }
};

int main() {
    Solution sol;
    vector<string> words;
    vector<char> letters;
    vector<int> score;

    // Output: 23
    words = {"dog","cat","dad","good"};
    letters = {'a','a','c','d','d','d','g','o','o'},
    score = {1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0};

    // Output: 27
    words = {"xxxz","ax","bx","cx"};
    letters = {'z','a','b','c','x','x','x'};
    score = {4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,10};

    // Output: 0
    //words = {"leetcode"};
    //letters = {'l','e','t','c','o','d'};
    //score = {0,0,1,1,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0};

    cout << "Result: " << sol.maxScoreWords(words, letters, score) << endl;
    
    return 0;
}
