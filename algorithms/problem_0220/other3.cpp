class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        //set to be used as sliding window, size must not exceed K else it will fall out of range
        set<int> s;
        for (int i=0;i<nums.size();++i)
        {
            // to find iterator to element just greater or equal to nums[i]
            auto it=s.lower_bound(nums[i]);
            if (it!=s.end() && llabs((long long)nums[i]-(long long)*it)<=t)
                return true;
            //to find element just less than or equal to nums[i]
            if (it!=s.begin())
            {
                auto it2=--it;
                if (llabs((long long)nums[i]-(long long)*it2)<=t)
                    return true;
            }
            s.insert(nums[i]);
            //if set size exceeds k, delete the oldest element
            if (s.size()>k)
                s.erase(nums[i-k]);
        }
        return false;
    }
};
