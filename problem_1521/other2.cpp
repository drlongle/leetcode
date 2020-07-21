class Solution {
public:
    int closestToTarget(vector<int>& arr, int t)
	{
		unordered_set<int> s1;
		int ans=INT_MAX;
		int n=arr.size();
		for(int i=0;i<n;i++)
		{
            ans = min(ans, abs(t - arr[i]));
			unordered_set<int> s2;
			s2.insert(arr[i]);
			for(auto a:s1)
			{
                a &= arr[i];
                ans=min(ans,abs(a-t));
				s2.insert(a);
			}
			s1 = s2;
		}
		return ans;
	}
};