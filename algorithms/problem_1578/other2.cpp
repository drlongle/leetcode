class Solution {
public:
    int minCost(string s, vector<int>& c)
    {
        int ans=0;
        for(int i=0;i<s.length()-1;i++)
        {
            if(s[i]==s[i+1])
            {
                int j=i,at=0,m1=INT_MIN;
                while(j<s.length() && s[j]==s[i])
                {
                    at+=c[j];
                    m1=max(m1,c[j++]);
                }
                i=j-1;
                at-=m1;
                ans += at;
            }
        }
        return ans;
    }
};
