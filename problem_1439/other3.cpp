/*
Solution derived from 373. Find K Pairs with Smallest Sums
Take first 2 rows, merge sum result and then solve for remaining rows, at the end return res[k-1].
 */
class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        vector<int> res = mat[0];
        for(int i=1;i<m;i++) {
            res = kSmallestPairs(res, mat[i],200);
        }
        return res[k-1];
    }
private:
    typedef tuple<int,int,int> tii;
    vector<int> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> res;
        set<pair<int,int>> seen;
        int m = nums1.size(), n = nums2.size();
        priority_queue<tii,vector<tii>,greater<tii>> pq;
        if(m == 0 || n == 0) return {};
        pq.emplace(nums1[0]+nums2[0],0,0);
        seen.insert({0,0});
        while(!pq.empty() && k) {
            auto [sum,i,j] = pq.top(); pq.pop();
            res.push_back(nums1[i] + nums2[j]);
            if(--k == 0) return res;
            if(i+1 < m) {
                int s1 = nums1[i+1] + nums2[j];
                if(!seen.count({i+1,j})) {
                    pq.emplace(s1,i+1,j);
                    seen.insert({i+1,j});
                }
            }
            if(j+1 < n) {
                int s2 = nums1[i] + nums2[j+1];
                if(!seen.count({i,j+1})) {
                    pq.emplace(s2,i,j+1);
                    seen.insert({i,j+1});
                }
            }
        }
        return res;
    }
};
