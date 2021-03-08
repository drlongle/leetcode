class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> table {{'1', '1'}, {'0', '0'}, {'8', '8'}, {'6', '9'}, {'9', '6'}};
        for (int i = 0, j = num.size() -1; i <= j; ++i, --j) {
            auto it = table.find(num[i]);
            if (it == table.end() || it->second != num[j])
                return false;
        }
        return true;
    }
};