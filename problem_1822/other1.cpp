class Solution {
public:
    int arraySign(vector<int>& n) {
        return count(begin(n), end(n), 0) ? 0 :
               count_if(begin(n), end(n), [](int i) { return i < 0;}) % 2 ? -1 : 1;
    }
};