class Solution {
public:
    int numTriplets(vector<int>& n1, vector<int>& n2) {
        return accumulate(begin(n1), end(n1), 0, [&](int s, long n) { return s + twoProduct(n * n, n2); })
               + accumulate(begin(n2), end(n2), 0, [&](int s, long n) { return s +  twoProduct(n * n, n1); });
    }
    int twoProduct(long i, vector<int> &n) {
        unordered_map<int, int> m;
        int cnt = 0;
        for (auto v : n) {
            if (i % v == 0)
                cnt += m[i / v];
            ++m[v];
        }
        return cnt;
    }
};