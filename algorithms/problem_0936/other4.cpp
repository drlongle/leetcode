class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        if(stamp.size() > target.size() || stamp[0] != target[0] || stamp.back() != target.back())
            return {};
        if(stamp.size() == target.size()) {
            if(stamp == target) return {0};
            return {};
        }

        int sizeS{(int)stamp.size()}, sizeT{(int)target.size()}, count{sizeT}, tmp;

        std::vector<int> res;

        while(count) {
            tmp = count;
            for(int i{0}; i <= sizeT-sizeS; ++i) {
                if(match(target, stamp, i, count)) res.emplace_back(i);
                if(!count) break;
            }

            if(tmp == count) return {};
        }

        std::reverse(res.begin(), res.end());
        return res;
    }

    bool match(string& target, string& stamp, int i, int& count) {
        int sizeS{(int)stamp.size()}, sizeT{(int)target.size()};
        bool valid{false};
        for(int j{i}, k{0}; k < sizeS && j < sizeT; ++j, ++k) {
            if(target[j] != '.') valid = true;
            else continue;

            if(stamp[k] != target[j]) return false;
        }

        if(valid) {
            for(int j{0}; j < sizeS; ++j) {
                if(target[j+i] != '.') target[j+i] = '.', --count;
            }

            return true;
        }

        return false;
    }
};
