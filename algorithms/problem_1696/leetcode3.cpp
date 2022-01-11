class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> tree(2 * n);
        update(0, nums[0], tree, n);
        for (int i = 1; i < n; i++) {
            int maxi = query(max(0, i - k), i, tree, n);
            update(i, maxi + nums[i], tree, n);
        }
        return tree[2 * n - 1];
    }

    // implement Segment Tree
    void update(int index, int value, vector<int>& tree, int n) {
        index += n;
        tree[index] = value;
        for (index >>= 1; index > 0; index >>= 1) {
            tree[index] = max(tree[index << 1], tree[(index << 1) + 1]);
        }
    }

    int query(int left, int right, vector<int>& tree, int n) {
        int result = INT_MIN;
        for (left += n, right += n; left < right; left >>= 1, right >>= 1) {
            if ((left & 1) == 1) result = max(result, tree[left++]);
            if ((right & 1) == 1) result = max(result, tree[--right]);
        }
        return result;
    }
};