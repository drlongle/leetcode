class Solution {
public:
    int GetNextIndex(int cur_index, int displacement, int n) {
        int next_index = cur_index + displacement;
        if (displacement >= 0)
            return next_index % n;
        if (next_index >= 0)
            return next_index;
        return next_index + n;
    }
    bool circularArrayLoop(vector<int>& nums) {
        if (nums.size() <= 1)
            return false;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] >= 0)
                nums[i] = nums[i] % nums.size();
            else
                nums[i] = -((-nums[i]) % nums.size());
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0)
                continue ;
            int direction = (nums[i] > 0) ? 1 : -1;
            set<int> visited;
            int cur = i;
            while (true) {
                if (visited.count(cur) > 0) 
                    return true;
                visited.insert(cur);
                int next_index = GetNextIndex(cur, nums[cur], nums.size());
                nums[cur] = 0;
                if (nums[next_index] == 0) {
                    if (visited.count(next_index) > 0)
                        return true;
                }
                if (nums[next_index] * direction > 0) {
                    cur = next_index;
                    continue ;
                } else {
                    break ;
                }
            }
        }
        return false;
    }
};
