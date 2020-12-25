class Solution {
public:
    int nextGreaterElement(int n) {
        string num = to_string(n);
        if (!next_permutation(num.begin(), num.end()))
            return -1;
        long long res = stol(num);
        return res <= numeric_limits<int>::max() ? res : -1;
    }
};

