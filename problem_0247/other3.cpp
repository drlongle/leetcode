class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        auto res = findStrobo(n);
        if (n > 1) {
            res.erase(remove_if(
                    res.begin(), res.end(), [](const string& s) {return s[0] == '0';}), res.end());
        }
        return res;

    }
    vector<string> findStrobo(int n) {
        if (n == 0) {
            return {""};
        }
        if (n == 1) {
            return {"0", "1", "8"};
        }
        auto smaller = findStrobo(n - 2);
        vector<string> res;
        for (auto&& word : smaller) {
            res.emplace_back("0" + word + "0");
            res.emplace_back("1" + word + "1");
            res.emplace_back("6" + word + "9");
            res.emplace_back("8" + word + "8");
            res.emplace_back("9" + word + "6");
        }
        return res;
    }
};
