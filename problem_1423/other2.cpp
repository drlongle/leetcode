class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        vector<int> left(k+1, 0);
        vector<int> right(k+1, 0);

        int ans = -1;
        for(int i = 1; i <= k; i++){
            left[i] = left[i-1] + cardPoints[i-1];
        }
        
        for(int i = 1; i <= k; i++){
            right[i] = right[i-1] + cardPoints[cardPoints.size()-i];
        }
    
        for(int i = 0; i <=k; i++){
            ans = max(ans, left[i]+right[k-i]);
        }

        return ans;
    }
};
