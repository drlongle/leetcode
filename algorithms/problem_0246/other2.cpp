class Solution {
private:
    std::unordered_map<char, char> map;
public:
    Solution() {
        this->map['0'] = '0';
        this->map['1'] = '1';
        this->map['6'] = '9';
        this->map['8'] = '8';
        this->map['9'] = '6';
    }
    bool isStrobogrammatic(string num) {
        bool res = false;
        int size = num.size();
        for (int idx=0; idx<size; idx++) {
            char trave_num = this->map[num[idx]];
            char target_num = num[size-1-idx];
            if (trave_num != target_num) {
                return false;
            }
        }
        return true;
    }
};
