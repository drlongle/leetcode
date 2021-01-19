class Solution {
    const int N = 2 * 1e4 + 1;
    const int origin = 1e4 + 1;
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> segtree(2*N, 0);
        vector<int> result;
        for (int i = nums.size()-1; i >= 0; i--) {
            result.push_back(rangeQuery(segtree, origin + nums[i]));
            update(segtree, origin + nums[i]);
        }
        // need to reverse result
        reverse(result.begin(), result.end());
        return result;
    }

    void update(vector<int>& segtree, int index) {
        for (index += N; index > 0; index >>= 1) {
            segtree[index]++;
        }
    }

    int rangeQuery(vector<int>& segtree, int entry) {
        int left = 0;
        int right = entry;
        int result = 0;
        for (left += N, right += N; left < right; left >>= 1, right >>= 1) {
            if (left%2 == 1) result += segtree[left++];
            if (right%2 == 1) result += segtree[--right];
        }
        return result;
    }
};
