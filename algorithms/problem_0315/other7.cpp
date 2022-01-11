class Solution {
public:
    // TIME COMPLEXITY:- O(NLOGM)
    // N = NUMS.SIZE()
    // M = 2e4 + 5
    // BIT Update
    void update(int ind,vector<int>& BIT){
        while(ind<=BIT.size()){
            BIT[ind]++;
            ind += ind & -ind;
        }
    }

    // BIT answer
    int answer(int ind,vector<int>& BIT){
        int ans = 0;
        while(ind>0){
            ans+=BIT[ind];
            ind -= ind & -ind;
        }
        return ans;
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        vector<int> BIT(20005,0); // Binary Indexed Tree Array
        for(int i=0;i<nums.size();i++){
            nums[i]+=10001; // Make all Numbers positive
        }
        for(int i=nums.size()-1;i>=0;i--){
            ans[i] = answer(nums[i]-1,BIT); // get answer
            update(nums[i],BIT); // update entry in BIT Array
        }
        return ans;
    }
};
// USING ORDERED SET
// NOTE:- This is Giving correct answer but I don't know why Leetcode doesn't support
// C++ Ordered Set functionality or May Be I'm committing some error.
// If anyone have done that, do share code of it.

#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

signed main()
{
    int n;
    cin>>n;
    vector<int> arr(n,0);
    vector<int> ans(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    ordered_set s;
    for(int i=n-1;i>=0;i--){
        ans[i] = s.order_of_key(arr[i]);
        s.insert(arr[i]);
    }

    for(auto it:ans){
        cout<<it<<" ";
    }
}
