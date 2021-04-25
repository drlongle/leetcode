class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        vector<long long> bit1(32), bit2(32);
        for(auto x : arr1)
            for(int i = 0; i < 31; i++)
                bit1[i] += (x >> i) & 1;
        for(auto x : arr2)
            for(int i = 0; i < 31; i++)
                bit2[i] += (x >> i) & 1;
        int ans = 0;
        for(int i = 0; i < 31; i++)
            if(bit1[i] * bit2[i] % 2)
                ans |= 1 << i;
        return ans;
    }
};
