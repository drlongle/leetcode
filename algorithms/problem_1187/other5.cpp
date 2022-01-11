/*
Only the replacement that would lower the value of arr1 is valid. Thus it is very similar with LIS problem.

The optimal structure is: f(i, prev) = min(f(i+1, arr[i]), f(i+1, upper_bound(arr2, prev)) + 1) if arr[i]>prev
f(i+1, upper_bound(arr2, prev)) + 1 otherwise.

Here f(i, prev) means the number of modifications to make the first i element of arr1 increasing with prev as the last element.
*/

struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1*37 + hash2; 
    } 
}; 


class Solution {
    unordered_map<pair<int, int>, int, hash_pair> memo;
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        int val= dfs(arr1, arr2, 0, -1);
        if(val>=3000)
            return -1;
        else
            return val;
    }
    
    
    int dfs(vector<int> & arr1, vector<int> & arr2, int i, int prev) {
        if(i==arr1.size())
            return 0;
        if(memo.count(make_pair(i, prev)))
            return memo[make_pair(i, prev)];
        int res = 0;
        int j = upper_bound(arr2.begin(), arr2.end(), prev) - arr2.begin();

        if(arr1[i]<=prev) {
            if(j>=arr2.size()) {
                res = 3000;
            } else {
                res = 1+dfs(arr1, arr2, i+1, arr2[j]);
            }
        } else {
            if(j>=arr2.size()||arr2[j]>=arr1[i]) {
                res =dfs(arr1, arr2, i+1, arr1[i]);
            } else {
                res = min(1+dfs(arr1, arr2, i+1, arr2[j]), dfs(arr1, arr2, i+1, arr1[i]));
            };
        }
        return memo[make_pair(i, prev)] = res;
    }
    
};
