// Binary Index Tree Implementation

class NumArray {
public:
    vector<int> bt, vv;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        vv = nums;
        bt.resize(n, 0);

        for(int i = 0; i < n; ++i) {
            add(i, nums[i]);
        }
    }

    void add(int ind, int val) {
        for(; ind < n; ind = ind | (ind + 1))
            bt[ind] += val;
    }

    void update(int ind, int val) {
        int diff = val - vv[ind];
        vv[ind] = val;
        add(ind, diff);
    }

    int sum(int r) {
        int ret = 0;
        for(; r >= 0; r = (r & (r + 1)) - 1)
            ret += bt[r];
        return ret;
    }

    int sumRange(int left, int right) {
        return sum(right) - sum(left - 1);
    }
};
