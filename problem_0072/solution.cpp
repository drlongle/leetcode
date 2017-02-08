/*
72. Edit Distance
Total Accepted: 60167 Total Submissions: 207668 Difficulty: Hard

Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/

#include <algorithm>
#include <array>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <functional>
#include <iomanip>
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

#define ll long long
#define ull unsigned long long

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2)
    {
        int size1 = word1.size();
        int size2 = word2.size();
        if (!size1 || !size2)
            return abs(size1 - size2);
        vector<vector<int>> dist = vector<vector<int>>(size1+1,
            vector<int>(size2+1));

        for (int i = 0; i <= size1; ++i)
            dist[i][0] = i;
        for (int i = 0; i <= size2; ++i)
            dist[0][i] = i;

        for (int i = 0; i < size1; ++i)
            for (int j = 0; j < size2; ++j)
            {
                if (word1[i] == word2[j])
                    dist[i+1][j+1] = dist[i][j];
                else
                    dist[i+1][j+1] = 1 +
                        min(min(dist[i][j+1], dist[i+1][j]), dist[i][j]);
            }
        return dist[size1][size2]; 
    }
};

int main()
{
    Solution sol;
    string word1, word2;
    word1= "cat";
    word2= "dog";
    cout << "Result: " << sol.minDistance(word1,word2) << endl;

    return 0;
}

