/*
1093. Statistics from a Large Sample
Medium

We sampled integers between 0 and 255, and stored the results in an array count:
count[k] is the number of integers we sampled equal to k.

Return the minimum, maximum, mean, median, and mode of the sample respectively,
as an array of floating point numbers.  The mode is guaranteed to be unique.

(Recall that the median of a sample is:
- The middle element, if the elements of the sample were sorted and the number of elements is odd;
- The average of the middle two elements, if the elements of the sample were sorted and the number of elements is even.)

Mode of of a set of data values: the value that appears most often.
https://en.m.wikipedia.org/wiki/Mode_(statistics)

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
#include <numeric>
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

struct Entry {
    Entry(int c, int v): count(c), value(v) {}
    int count, value;
};

int get_level(vector<int>& count, int level)
{
    int sum = 0;
    for (int i = 0; i < static_cast<int>(count.size()); ++i) {
        sum += count[i];
        if (sum >= level)
            return i;
    }
    return -1;
}

class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        vector<double> res;
        int minv = numeric_limits<int>::max();
        int maxv = numeric_limits<int>::min();
        double sum = 0;
        int nsize = 0;
        
        if (count.empty())
            return {0, 0, 0, 0, 0};

        vector<Entry> entries;

        for (int i = 0; i < static_cast<int>(count.size()); ++i) {
            if (!count[i])
                continue;
            entries.emplace_back(count[i], i);
            sum += i*count[i];
            nsize += count[i];
            minv = min(minv, i);
            maxv = max(maxv, i);
            
        }

        auto it = max_element(begin(entries), end(entries), [] (const Entry& e1, const Entry& e2)
                                                            {return e1.count < e2.count;});

        double median = 0;
        int mid = nsize / 2;
        if (nsize & 1) {
            median = get_level(count, mid);
        } else {
            median = static_cast<double>(get_level(count, mid) + get_level(count, mid+1))/2;
        }

        return {static_cast<double>(minv), static_cast<double>(maxv), sum/nsize, median, static_cast<double>(it->value)};
    }
};

int main()
{
    Solution sol;
    vector<int> count;

    // Expected: [1.00000,3.00000,2.37500,2.50000,3.00000]
    count = {0,1,3,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    // Expected: [1.00000,4.00000,2.18182,2.00000,1.00000]
    count = {0,4,3,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    
    auto res = sol.sampleStats(count);

    copy(begin(res), end(res), ostream_iterator<double>(cout, ", "));
    cout << endl;

    return 0;
}

