// odd/even split
//
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq)
    {
        vector<int> res;
        int level = 0;
        for (char c : seq) {
            if (c == '(') {
                res.push_back(++level % 2);
            } else if (c == ')') {
                res.push_back(level-- % 2);
            }
        }
        return res;
    }
};
