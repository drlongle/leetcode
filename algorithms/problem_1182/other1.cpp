class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        int n = colors.size();
        for(int& x:colors)x--;
        vector<vector<int>> c(3,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                if(j==colors[i]){
                    c[j][i]=0;
                }
                else{
                    if(i!=0)
                        c[j][i]=min(c[j][i-1]==INT_MAX?INT_MAX:c[j][i-1]+1,c[j][i]);
                }
                if(j==colors[n-i-1]){
                    c[j][n-i-1]=0;
                }
                else{
                    if(n-i-1!=n-1)
                        c[j][n-i-1]=min(c[j][n-i]==INT_MAX?INT_MAX:c[j][n-i]+1,c[j][n-i-1]);
                }
            }
        }
        vector<int> ans;
        for(auto q:queries){
            ans.push_back(c[q[1]-1][q[0]]==INT_MAX?-1:c[q[1]-1][q[0]]);
        }
        return ans;
    }
};