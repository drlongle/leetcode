/*
1. For Every element of the array, try to find the minimum left bound and maximum right bound
   of current subarray such that arr[i] remains as maximum element.
2. Our answer will be increased by (backwardCount * forwardCount)
3. How to find above two unknown values for every array element efficiently?
4. Binary Search
5. Sort pairs{nums[i],i} in non decreasing order.
6. Iterate from backside of this vector and store indices of elements in a set.
7. For current element to remain as maximum, left bound and rightbound, we can easily get with the help of binary search.
*/

class Solution {
public:
    // TIME COMPLEXITY:- O(NLOG(N))
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int ans = 0,n = nums.size();
        vector<pair<int,int>> v;
        // sort on the basis of {nums[i],i}
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        set<int> index = {-1,n}; // base values

        // For each iteration, we consider subarrays whose maximum value is at position v[i].second
        // and count these subarrays. All of them start at index 0 and at (index.upper_bound(v[i].second) - 1).
        for(int i=n-1;i>=0;i--) {
            index.insert(v[i].second);
            // if v[i].first is the maximum element
            if(v[i].first>right or v[i].first<left)
                continue;
            auto next_itr = index.upper_bound(v[i].second);
            auto prev_itr = index.find(v[i].second);
            prev_itr--;
            int backward = v[i].second - (*prev_itr); // max_right
            int forward = (*next_itr) - v[i].second;  // max_left
            ans+=(backward*forward); // no of subarrays possible for current maximum element
        }
        return ans;
    }
};
