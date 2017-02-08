/*
386. Lexicographical Numbers

    User Accepted: 297
    User Tried: 503
    Total Accepted: 107
    Total Submissions: 694
    Difficulty: Medium

Given an integer n, return 1 - n in lexicographical order.

For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].

Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000
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
    vector<int> lexicalOrder(int n)
    {
        vector<int> res(n);
        string s;
        int index = 0;
        add_elements(s, index, n, res);
        return res;
    }

    void add_elements(string& st, int& index, int& n, vector<int>& res) 
    {
        char ch = st.empty() ? '1' : '0';
        st.append(1, ' ');
        for ( ; ch <= '9'; ++ch) {
            st.back() = ch;
            int temp = stoi(st);
            if (temp > n)
                break;
            res[index++] = temp;
            add_elements(st, index, n, res);
        }
        st.resize(st.size()-1);
    }
};

int main(int argc, const char* argv[])
{
    if (argc < 1) {
        cerr << "Usage: " << argv[0] << " <number>" << endl;
        exit(1);
    }

    Solution sol;
    vector<int> res;
    int n = stoi(argv[1]);

    res = sol.lexicalOrder(n);
    copy(res.begin(), res.end(), ostream_iterator<int>(cout, ","));

    return 0;
}

