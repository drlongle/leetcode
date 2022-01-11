class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> uset;
        for (int l = 1; l + 1 <= bound; l *= x) {
            for (int r = 1; l + r <= bound; r *= y) {
                uset.emplace(l + r);
                if (y == 1)
                    break;
            }
            if (x == 1)
                break;
        }

        return {uset.begin(), uset.end()};
    }
};
