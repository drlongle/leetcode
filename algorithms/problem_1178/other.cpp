/*
The question asks for the number of words that satisfy the condition for each puzzle. Let M = words.size(), N =
words.size(). It seems that the time complexity is at least O(MN) without considering the overhead of processing each
word/puzzle as one have to verify each pair, but we should seek alternative ways to retrive answer.

Before that, we first think about how should we process these words and puzzles. A brute-force solution is to save
whether a character exists in a word/puzzle, which takes a space of O(26(M+N)), and when it comes to verification, one
needs O(26) (but it is still a constant) for each pair.

To save memory space, observe that for all 26 alphabets, the status is either true (exist) or false, and 2^26 < INT_MAX,
so one can use one integer to represent each word. Note that there might exist some words that have the same integer
representation, and by using a map or unordered_map we can potentially reduce the running time. Let s[i] denote the
number of words of the same integer representation i.

We now think about how should we find the solution for each puzzle. Observe that N <= 10^5 and M < 10^4, it is
infeasible to use an algorithm of O(MN). Then observe that puzzles[i].length == 7, then for each puzzle, there are at
most 2^6 feasible integer representation (note the first requirement: word contains the first letter of puzzle). So
eventually, for each puzzle, we can enumerate all feasible integers i and sum over all s[i].

The time complexity for processing all words is O(kM) assuming we are using unordered_map with time complexity O(1) for
each find and add operation, and k = words[i].length <= 50, and for find solutions for each word O(mN), where m= 2^6. It
is a total of O(kM + mN).
*/

#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    unordered_map<int, int> s;
    vector<int> ans;
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles)
    {
        vector<vector<int>> p(26);
        const int N = words.size();
        const int M = puzzles.size();
        ans.resize(M, 0);
        for (int i = 0; i < N; ++i) {
            int k = 0;
            int cnt = 0;
            for (int j = 0; j < words[i].size(); ++j) {
                if ((k & (1 << (words[i][j] - 'a'))) == 0) {
                    cnt++;
                    if (cnt > 7)
                        break;
                    k = (k | (1 << (words[i][j] - 'a')));
                }
            }
            if (cnt <= 7) {
                if (s.find(k) == s.end())
                    s[k] = 1;
                else
                    s[k]++;
            }
        }

        for (int i = 0; i < M; ++i) {
            vector<int> all_p;
            all_p.push_back(1 << (puzzles[i][0] - 'a'));
            for (int j = 0; j < puzzles[i].size(); ++j) {
                int K = all_p.size();
                for (int m = 0; m < K; ++m)
                    if ((all_p[m] & (1 << (puzzles[i][j] - 'a'))) == 0)
                        all_p.push_back(all_p[m] | (1 << (puzzles[i][j] - 'a')));
            }
            for (int j = 0; j < all_p.size(); ++j)
                if (s.find(all_p[j]) != s.end())
                    ans[i] += s[all_p[j]];
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<string> words, puzzles;

    // Output: [1]
    words = {"aaaaaaaaaaaax"};
    puzzles = {"abc"};

    auto res = sol.findNumOfValidWords(words, puzzles);

    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    return 0;
}
