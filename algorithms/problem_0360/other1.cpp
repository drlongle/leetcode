class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& ns, int a, int b, int c) {
        auto f = [&](int i) { return a * ns[i] * ns[i] + b * ns[i] + c; };
        vector<int> res;
        for (int i = 0, j = ns.size() - 1; i <=j;)
            if ((a > 0 && f(i) > f(j)) || (a <= 0 && f(i) < f(j)))
                res.push_back(f(i++));
            else
                res.push_back(f(j--));
        if (a > 0)
            reverse(begin(res), end(res));
        return res;
    }
};