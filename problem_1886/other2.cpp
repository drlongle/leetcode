class Solution {
public:
    bool findRotation(std::vector<std::vector<int>>& mat,
                      std::vector<std::vector<int>>& target) {
        size_t n = mat.size();
        for (int i = 0; i < 4; ++i) {
            if (mat == target) {
                return true;
            }
            rotateRight(target, n);
        }
        return false;
    }
    void rotateRight(std::vector<std::vector<int>>& target, size_t n) {
        using std::swap;

        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < i; j++) {
                swap(target[i][j], target[j][i]);
            }
        }

        for (auto& target : target) {
            std::reverse(target.begin(), target.end());
        }
    }
};
