class Solution {
    typedef pair<int,int> p;
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<p,vector<p>,greater<p>> min_heap;
        for(auto val : arr)
        {
            min_heap.push({abs(val-x),val});
        }
        vector<int> nums;
        while(k--)
        {
            nums.push_back(min_heap.top().second);
            min_heap.pop();
        }
        sort(nums.begin(),nums.end());
        return nums;
    }
};
