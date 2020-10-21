class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        int n=a.size();
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            while(ans.size()>0 && a[i]<0 &&ans[ans.size()-1]>0 && ans[ans.size()-1]<abs(a[i]))
                ans.pop_back();
            if(ans.size()>0 && a[i]<0 && ans[ans.size()-1]>0 && ans[ans.size()-1]==abs(a[i]))
            {
                ans.pop_back();
                continue;
            }

            if (ans.size()==0 || ans[ans.size()-1]<0 && a[i]<0
                || ans[ans.size()-1]>0 && a[i]>0 || ans[ans.size()-1]<0 && a[i]>0)
                ans.push_back(a[i]);
        }
        return ans;
    }
};
