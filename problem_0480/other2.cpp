class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k)
    {
        vector<double> median;
        multiset<int> window(nums.begin(), next(nums.begin(), k));
        auto mid = next(window.begin(), k / 2);
        for(int i = k; ; i++)
        {
            if(k & 1) median.push_back(*mid);
            else median.push_back((double(*prev(mid)) + double(*mid)) * 0.5);
            if(i == nums.size()) break;
            window.insert(nums[i]);

            if(nums[i] < *mid && (k & 1) == 0)
                --mid;
            else if(nums[i] >= *mid && k & 1)
                ++mid;

            if(nums[i - k] < *mid)
            {
                window.erase(window.find(nums[i - k]));
                if((k + 1) & 1)
                    ++mid;
            }
            else if(nums[i - k] > *mid)
            {
                window.erase(window.find(nums[i - k]));
                if(((k + 1) & 1) == 0)
                    --mid;
            }
            else
            {
                mid = window.erase(mid);
                if(((k + 1) & 1) == 0)
                    --mid;
            }
        }

        return median;
    }
};
