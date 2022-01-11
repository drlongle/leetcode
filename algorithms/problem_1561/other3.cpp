class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end(),greater<>());
        int j=piles.size()-1;
        int i=0;
        int sum=0;

        while(i<j)
        {
            i++;
            sum=sum+piles[i];
            i++;
            j--;
        }

        return sum;
    }
};