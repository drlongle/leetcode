class Solution {
public:
    string maxValue(const string& n, int x) {
        string res;
        res.reserve(n.size()+1);

        auto i = (n.front() != '-') ? find_if(n.begin(), n.end(), [x] (char c) { return c - '0' < x;}) : find_if(n.begin()+1, n.end(), [x] (char c) { return c - '0' > x;});
        res.append(n.begin(), i).append(1, x + '0').append(i, n.end());
        return res;
    }
};
