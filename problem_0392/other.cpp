
class Solution {
public:

// find the first value thats greater than val
    int nextVal(vector<int> &nums, int val)
    {
        int start = 0;
        int end = nums.size();
        if(nums.size() == 1)
            return nums[0];
        while(start < end)
        {
            int mid = start + (end-start)/2;
            if(nums[mid] > val)
                end = mid;
            else
                start = mid+1;
        }
        return nums[start];
    }
    bool isSubsequence(string s, string t) {
// map to store a list of all indices per unique character. note the list will be sorted
        unordered_map<char, vector<int>> m;
        for(int i = 0; i < t.size(); i++)
            m[t[i]].push_back(i);
        int prev = -1;
        for(int i = 0; i < s.size(); i++)
        {
            if(!m.count(s[i])) return false;
            int nextIndex = nextVal(m[s[i]], prev);
            if(nextIndex <= prev)
                return false;
            prev = nextIndex;
        }
        return true;
    }
};

