/*
220. Contains Duplicate III

Given an array of integers, find out whether there are two distinct indices i and j in the array such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k. 

Solution sketch.

Go through the array of integers and organize them into bins. Each bin is
indexed by the value of the integers. Each bin contains the index of the
elements in the original array. Because a map is used to construct the bins,
they are automatically sorted by the integer values.

Now copy the bins to a new array and go through the new array to see if
there are elements such that their difference is at most k. If so, try to see
whether these elements have indices such that the difference of the indices
is at most k.
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

struct value_entry
{
    value_entry(int v): m_value(v) { }
    long long int m_value;
    vector<int> m_positions;
};

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<int, vector<int>> lookup;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            int n = nums[i];
            lookup[n].push_back(i);
        }

        vector<value_entry> values;
        for (auto const& l: lookup)
        {
            values.emplace_back(l.first);
            move(l.second.begin(), l.second.end(),
                back_inserter(values.back().m_positions));
        }

        if (t >= 0)
        {
            for (size_t i = 0; i < values.size(); ++i)
                for (size_t x = 1; x < values[i].m_positions.size(); ++x)
                    if ((values[i].m_positions[x] - values[i].m_positions[x-1]) 
                        <= k)
                        return true;
        }

        for (size_t i = 0; i < values.size(); ++i)
            for (size_t j = i+1; j < values.size(); ++j)
            {
                if (abs(values[i].m_value - values[j].m_value) > t)
                    break;
                for (size_t x = 0; x < values[i].m_positions.size(); ++x)
                    for (size_t y = 0; y < values[j].m_positions.size(); ++y)
                    {
                        int diff = values[j].m_positions[y] -
                            values[i].m_positions[x];
                        if (abs(diff) <= k)
                            return true; 
                        if (diff > k)
                            break; 
                    }
            }

        return false;
    }
};

int main()
{
    Solution sol;
    vector<int> input;
    int k, t;

    input = {6,26,3,9,19};
    k = 2, t = 10;
    cout << "Result: " << boolalpha
         << sol.containsNearbyAlmostDuplicate(input, k, t);

    return 0;
}
