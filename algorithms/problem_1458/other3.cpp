class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size()+1, vector<int>(nums2.size()+1));
        for(int i = 0; i<=nums1.size(); i++){
            dp[i][0] = INT_MIN;
        }

        for(int i =0; i<=nums2.size(); i++){
            dp[0][i] = INT_MIN;
        }
		// state [num1 element] [num2 element], decision whether or not to include the pair
        for(int i = 1; i<=nums1.size(); i++){
            
            for(int j = 1; j<=nums2.size(); j++){
                int withOut = max(dp[i-1][j], dp[i][j-1]);
                int with = dp[i-1][j-1] < 0 ? nums1[i-1]*nums2[j-1] : dp[i-1][j-1] + nums1[i-1]*nums2[j-1];       // Kadane like ignoring prev values if less than zero
                dp[i][j] += max(with, withOut); // LCS like decisions 
            }

        }
        return dp.back().back();
    }
};
