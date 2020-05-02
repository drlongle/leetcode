class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans =0;
        int n = cardPoints.size();

        for(int i = n-k; i<n ; i++){
            ans+=cardPoints[i];
        }

        int comp = ans;
        int i =0;
        int j =n-k;

        while(k--){
            comp -= cardPoints[j++];
            comp +=cardPoints[i++];
            ans = max(ans, comp);
        }

        return ans;
    }
};
