class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        if (k <= 0 || nums.size() < k) return {};
        // order by value and index.
        auto cmp_less = [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second != rhs.second ? lhs.second < rhs.second : lhs.first < rhs.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp_less)> max_heap(cmp_less);
        auto cmp_greater = [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second != rhs.second ? lhs.second > rhs.second : lhs.first > rhs.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp_greater)> min_heap(cmp_greater);
        for (int i = 0; i < k; ++i) {
            max_heap.push({i, nums[i]});
        }
        for (int j = 0; j < k/2; ++j) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        vector<double> result(nums.size()-k+1);
        result[0] = (k&1 ? max_heap.top().second : 0.5 * min_heap.top().second + 0.5 * max_heap.top().second);

        for (int i = 1; i+k-1 < nums.size(); ++i) {
            int iend = i+k-1;
            // condition will be based on max_heap which will be always non-empty.
            if (nums[iend] >= max_heap.top().second) {
                // iend is right most, place on right if possible. if nums[iend] = max_heap.top().second, push min_heap,
                // so that min_heap.top() reflects smallest index with value max_heap.top().second.
                min_heap.push({iend, nums[iend]});
                if (nums[i-1] <= max_heap.top().second) {
                    // i-1 is in max_heap, should be removed from max_heap even if multiple occurrence by index order (i-1 is left most).
                    // max_heap will remove i-1 and then imbalanced. So rebalance now.
                    max_heap.push(min_heap.top());
                    min_heap.pop();
                }  // otherwise min_heap insert one, will remove one, balanced.
            } else {
                max_heap.push({iend, nums[iend]});
                if (nums[i-1] > max_heap.top().second) {
                    // nums[i-1] is on the min_heap, should be removed.
                    // min_heap will remove i-1 and imbalanced. So rebalance now.
                    min_heap.push(max_heap.top());
                    max_heap.pop();
                } // otherwise max_heap insert one, will remove one, balanced.
            }
            // lazy removal of out of window numbers.
            while(max_heap.size() && max_heap.top().first < i) max_heap.pop();
            while(min_heap.size() && min_heap.top().first < i) min_heap.pop();

            result[i] = (k&1 ? max_heap.top().second : 0.5 * min_heap.top().second + 0.5 * max_heap.top().second);
        }
        return result;
    }
};
