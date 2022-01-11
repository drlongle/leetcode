class Solution {
public:
    vector<int> frequencySort(vector<int>& A) {
        unordered_map<int, int> cnt;
        for (int n : A) cnt[n]++;
        sort(begin(A), end(A), [&](int a, int b) { return cnt[a] != cnt[b] ? cnt[a] < cnt[b] : a > b; });
        return A;
    }
};
