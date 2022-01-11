//
// using monotonic deque
//

class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        std::deque<int> dq;
        int count{0};
        for(int i{0}, size{(int)nums.size()}; i < size; ++i) {
            while(!dq.empty() && nums[i] < nums[dq.back()]) count += i - dq.back(), dq.pop_back();
            dq.emplace_back(i);
        }
        while(!dq.empty()) {
            count += dq.back() - dq.front() + 1;
            dq.pop_front();
        }
        return count;
    }
};
