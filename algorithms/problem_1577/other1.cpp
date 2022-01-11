class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int64_t, int> freq1, freq2;
        for (int n : nums1) freq1[n]++;
        for (int n : nums2) freq2[n]++;

        auto Count = [](unordered_map<int64_t, int> &freqX, unordered_map<int64_t, int> &freqY) {
            int cnt = 0;
            for (auto [n1, f1] : freqX) {
                int c = 0;
                int64_t n1sq = n1*n1;
                for (auto [n2, f2] : freqY) {
                    if (n2 == n1) {
                        if (f2 > 1) c += f2*(f2 - 1)/2;
                    } else if (n2 < n1 && n1sq % n2 == 0) {
                        int n2x = n1sq/n2;
                        if (freqY.count(n2x)) c += f2*freqY[n2x];
                    }
                }
                cnt += c*f1;
            }
            return cnt;
        };

        return Count(freq1, freq2) + Count(freq2, freq1);
    }
};