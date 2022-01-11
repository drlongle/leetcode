/*
315. Count of Smaller Numbers After Self

    Total Accepted: 19259
    Total Submissions: 59109
    Difficulty: Hard

You are given an integer array nums and you have to return a new counts array.
The counts array has the property where counts[i] is the number of smaller
elements to the right of nums[i].

Example:
Given nums = [5, 2, 6, 1]

To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.

Return the array [2, 1, 1, 0].
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

class Node {
public:
    Node(int val) : value(val), count(1), size(0), left(NULL), right(NULL) {}
    ~Node() {
        delete left;
        delete right;
    }

    int insert(int val, int c) {
        if (value == val) {
            ++count;
            return c + size;
        } else if (val < value) {
            ++size;
            if (left)
                return left->insert(val, c);
            else {
                left = new Node(val);
                return c;
            }
        } else {
            if (right)
                return right->insert(val, c + count + size);
            else {
                right = new Node(val);
                return count + size + c;
            }
        }
    }

private:
    int value;
    int count;
    int size;
    Node *left, *right;
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res;
        int N = nums.size();
        if (!N) return res;
        Node* root = new Node(nums[N-1]);
        res.emplace_back(0);

        for (int i = N - 2; i >= 0; --i) {
            int n = root->insert(nums[i], 0);
            res.emplace_back(n);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

int main(int argc, const char* argv[])
{
    Solution sol;

    vector<int> nums, res;

    // Expected: [2, 1, 1, 0]
    nums = {5, 2, 6, 1};
    res = sol.countSmaller(nums);
    copy(res.begin(), res.end(), ostream_iterator<int>(cout, ", "));

    return 0;
}

