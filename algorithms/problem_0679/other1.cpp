class Solution {
  public:
    bool judgePoint24(vector<int> &cards) {
        sort(cards.begin(), cards.end());
        do {
            auto vals = backtrack(cards, 0, 3);
            for (auto val : vals) {
                if (isAns(val))
                    return true;
            }
        } while (next_permutation(cards.begin(), cards.end()));
        return false;
    }

    bool isAns(double val) {
        if (abs(val - 24.0) < 0.0001)
            return true;
        return false;
    }

    vector<double> backtrack(vector<int> &cards, int left, int right) {
        if (left == right)
            return {static_cast<double>(cards[left])};
        vector<double> result;
        for (int i = left; i < right; ++i) {
            auto vals1 = backtrack(cards, left, i);
            auto vals2 = backtrack(cards, i + 1, right);

            for (int i = 0; i < vals1.size(); ++i) {
                for (int j = 0; j < vals2.size(); ++j) {
                    result.push_back(vals1[i] * vals2[j]);
                    result.push_back(vals1[i] / vals2[j]);
                    result.push_back(vals1[i] + vals2[j]);
                    result.push_back(vals1[i] - vals2[j]);
                }
            }
        }
        return result;
    }
};
