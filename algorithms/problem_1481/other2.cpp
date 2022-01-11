
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k)
    {
        map<int,int> m;
        vector<int> v;
        for(auto a:arr)m[a]++;
        for(auto a:m)
        {
            v.push_back(a.second);
        }
        int ans=m.size();
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
        {
            if(k==0||k<v[i])return ans;
            k-=v[i];
            ans--;
        }
        return ans;
    }
};
