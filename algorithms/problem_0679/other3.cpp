class Solution {
  public:
    bool judgePoint24(vector<int> &cards) {
        vector<double> init;
        for (auto n : cards)
            init.push_back(n);
        return get24(init);
    }

    bool get24(vector<double> &nums) {
        if (nums.empty())
            return false;
        if (nums.size() == 1)
            return abs(nums[0] - 24) < 1e-6;

        int N = nums.size();
        for (int i = 0; i < N - 1; ++i) {
            for (int j = i + 1; j < N; ++j) { // pick 2 number
                vector<double> next;
                for (int k = 0; k < N; ++k) // put remain number
                    if (i != k && j != k)
                        next.push_back(nums[k]);
                for (int op = 0; op < 6; ++op) {
                    double opNum = getOperNum(op, nums[i], nums[j]);
                    if (opNum != 1e9) {
                        next.emplace_back(opNum);
                        if (get24(next))
                            return true;
                        next.pop_back();
                    }
                }
            }
        }
        return false;
    }

    double getOperNum(int op, double n1, double n2) {
        if (op == 0)
            return n1 + n2;
        if (op == 1)
            return n1 * n2;
        if (op == 2)
            return n1 - n2;
        if (op == 3)
            return n2 - n1;
        if (op == 4 && n2 != 0)
            return n1 / n2;
        if (op == 5 && n1 != 0)
            return n2 / n1;
        return 1e9;
    }
};
