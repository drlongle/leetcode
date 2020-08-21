class Solution {
public:
    vector<int> findClosestElements(vector<int>& a,int k, int x) {
        int n=a.size(),i;
        int index=upper_bound(a.begin(),a.end(),x)-a.begin();
        vector<int> ans;
        int l=index-1,r=index;
        while(k&&l>=0&&r<n)
        {
            k--;
            if(x-a[l]<=a[r]-x)
                ans.push_back(a[l--]);
            else
                ans.push_back(a[r++]);
        }
        while(k&&l>=0)
        {
            k--;
            ans.push_back(a[l--]);
        }
        while(k&&r<n)
        {
            k--;
            ans.push_back(a[r++]);
        }
        sort(ans.begin(),ans.end());

        return ans;
    }
};
