class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> window;
        multiset<long long> ms;
        int start=0;
        for(int i=0; i<nums.size(); i++) {
            ms.insert(nums[i]);
            if(i>=k-1) {
                auto cur_mid=next(ms.begin(),k/2);     // get the mid pointer
                auto prev_mid=prev(cur_mid,1-(k%2));  // get the prev mid pointer
                double mid_val=*cur_mid+*prev_mid;   //  get the middle value
                window.push_back(mid_val/(double)2);
                ms.erase(ms.find(nums[start]));      // remove the value outside the segment k from the left when i>=k-1
                start++;
            }
        }
        return window;
    }
};
