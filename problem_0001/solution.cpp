
/*
1. Two Sum

Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2 

 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

struct MyNum {
    int m_index;
    int m_value;
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result = {-1, -1};
        vector<MyNum> mynums;
        MyNum num;
        for (int i = 0; i < nums.size(); ++i) {
            num.m_index = i+1;
            num.m_value = nums[i];
            mynums.emplace_back(num);
        }
        sort(mynums.begin(), mynums.end(),
            [](const MyNum& a, const MyNum&b) -> bool
            { return a.m_value < b.m_value;});

        int index1 = 0, index2 = mynums.size() - 1;
        while (index1 < index2) {
            int sum = mynums[index1].m_value + mynums[index2].m_value;
            if (sum < target)
                index1++;
            else if (sum == target) {
                result[0] = min(mynums[index1].m_index, mynums[index2].m_index);
                result[1] = max(mynums[index1].m_index, mynums[index2].m_index);
                break;
            } else
                index2--;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> nums{3, 2, 4};
    int target = 6;
    vector<int> result = solution.twoSum(nums, target);
    cout << "index1=" << result[0] << ", index2=" << result[1] << endl;
}

