/*
60. Permutation Sequence  
Total Accepted: 52837 Total Submissions: 210752 Difficulty: Medium

The set [1,2,3,...,n] contains a total of n! unique permutations.
By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

    "123"
    "132"
    "213"
    "231"
    "312"
    "321"
Given n and k, return the kth permutation sequence.
*/

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <functional>
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
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> digits(n);
        stringstream oss;
        iota(digits.begin(), digits.end(), 1);

        vector<long long> fact(n+2);
        fact[0] = fact[1] = 1;
        for (int i = 2; i <= n; ++i)
            fact[i] = i*fact[i-1];

        k--;
        while (k > 0)
        {
            int temp = fact[digits.size()-1];
            int index = k / temp;
            oss << digits[index];
            k %= temp;
            digits.erase(digits.begin()+index); 
        }

        for (const auto& d: digits)
            oss << d;

        return oss.str();
    }
};

int main()
{
    Solution sol;
    int n,k;

    cout << "n: ";
    cin >> n;
    cout << "k: ";
    cin >> k;
    cout << "Answer: " << sol.getPermutation(n,k) << endl;

    return 0;
}

