class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2, int a = 0, int b = 0){
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        for(auto x : arr1) a ^= x;
        for(auto x : arr2) b ^= x;
        return a & b;
    }
};
