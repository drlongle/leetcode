class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        int bitPos = 0;
        for(int bit = 0; bit < 32; bit++) {
            for(int i = 0; i < n; i++) {
                if(arr1[i] & (1 << bit)) {
                    bitPos ^= (1 << bit);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < m; i++) {
            ans ^= (bitPos & arr2[i]);
        }
        return ans;
    }
};
