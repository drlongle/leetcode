class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        if(n == 0) return 0;
        
        multimap<int, int> h;
        for (int i=0; i<n; i++) {
            h.emplace(heights[i], i);
        }
        
        set<int> inds; // upper bound yields R
        set<int> rinds; // upper bound yields -L
        int best = INT_MIN;
        for (auto &kv : h) {
            int val = kv.first;
            int ind = kv.second;
            
            auto itr1 = inds.upper_bound(ind);
            auto itr2 = rinds.upper_bound(-ind);
            int r = itr1 == inds.end() ? n-1 : *itr1 - 1;
            int l = itr2 == rinds.end()  ? 0 : -*itr2 + 1;
            
            int w = r - l + 1;
            
            best = max(best, w * val);

            inds.emplace(ind);
            rinds.emplace(-ind);
        }
        return best;
    }
};

