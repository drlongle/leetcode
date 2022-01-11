/*
65. Valid Number

Validate if a given string is numeric.
Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
*/

#include <algorithm>
#include <cassert>
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
    bool isNumber(string s) {
        int size = static_cast<int>(s.size());
        int i = 0;

        while (i < size && (s[i] == ' ' || s[i] == '\t'))
	    ++i;

        if (s[i] == '+' || s[i] == '-')
	    ++i;

        if (i == size)
	    return false;

        bool has_integer = false;
        bool has_fraction = false;
        bool has_exponent = false;
        if (isdigit(s[i])) {
	    has_integer = true;
	    while (i < size && isdigit(s[i])) {
	        ++i;
	    }
            if (i == size)
                return true;
        }

        if (s[i] == '.') {
	    ++i;
	    while (i < size && isdigit(s[i])) {
	        ++i;
                has_fraction = true;
	    }

	    if (!has_integer && !has_fraction)
	        return false;
            if (i == size) return true;
        }

        if (s[i] == 'e' || s[i] == 'E') {
	    if (!has_integer && !has_fraction)
	        return false;

	    if (++i == size) return false;
	    if (s[i] == '+' || s[i] == '-')
	        if (++i == size) return false;

	    while (i < size && isdigit(s[i])) {
	        ++i;
	        has_exponent = true;
	    }
            if (!has_exponent)
	        return false;
        }

        while (i < size && (s[i] == ' ' || s[i] == '\t'))
	    ++i;

        return i == size;
    }
};

int main()
{
    Solution sol;
    string input;
    input = "0";
    cout << boolalpha << input << " -> " << sol.isNumber(input) << endl;

    return 0;
}
