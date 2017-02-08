/*
231. Power of Two  
Total Accepted: 67992 Total Submissions: 187364 Difficulty: Easy

Given an integer, write a function to determine if it is a power of two. 
*/

#include <algorithm>
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
#include <vector>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long m = n;
        if (!m) return false;
        return (m & (m-1)) == 0;
    }
};

int main()
{
    return 0;
}

