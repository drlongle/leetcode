class Solution {
public:
    void util(vector<string> &res, string subres, unordered_map<char, char> &m,
              int start, int end) {
        if(start > end) {
            res.push_back(subres);
            return;
        }
        for(auto &itr : m) {
            char first = itr.first, second = itr.second;
            if(start == end and (first != '6' and first != '9')) {
                subres[start] = first;
                util(res, subres, m, start + 1, end - 1);
            } else if(start < end) {
                if(start == 0 and first == '0') continue;
                subres[start] = first;
                subres[end] = second;
                util(res, subres, m, start + 1, end -1);
            }
        }
    }
    vector<string> findStrobogrammatic(int n) {
        unordered_map<char, char> m = {{'1','1'}, {'6','9'},
                                       {'9','6'}, {'8','8'},
                                       {'0','0'}};
        vector<string> res;
        string subres(n, ' ');
        util(res, subres, m, 0, n - 1);
        return res;
    }
};
