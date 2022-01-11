/*
28. Implement strStr()

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack. 
*/

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <climits>
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
#include <vector>

#include <string.h>

using namespace std;

class Solution {
public:
    static const int hash_value = 1993;
    int strStr(string haystack, string needle)
    {
        int result = -1;
        long long n_sum = 0, h_sum = 0, multi = 1;
        int n_size = static_cast<int>(needle.size());
        for (int i = 0; i < n_size; ++i)
            n_sum = (n_sum*256 + needle[i]) % hash_value;

        int h_size = static_cast<int>(haystack.size());
        if (h_size < n_size) return -1;

        for (int i = 0; i < n_size ; ++i)
            h_sum = (h_sum*256 + haystack[i]) % hash_value;

        for (int j = 0; j < n_size-1 ; ++j) multi = multi * 256 % hash_value;

        if (n_sum == h_sum) {
            if (haystack.compare(0, n_size, needle) == 0)
                return 0;
        }

        for (int i = n_size; i < h_size ; ++i)
        {
            h_sum = (h_sum - haystack[i-n_size]*multi) % hash_value;
            if (h_sum < 0) h_sum += hash_value;
                h_sum = (h_sum*256 + haystack[i]) % hash_value;
                if (n_sum == h_sum) {
                    if (haystack.compare(i-n_size+1, n_size, needle) == 0)
                        return i-n_size+1;
                }
        }
        return result; 
    }
};


int main()
{
    string haystack("mississippi");
    string needle("pi");
    Solution sol;
    cout << "-> " << sol.strStr(haystack, needle) << endl;

    return 0;
}

