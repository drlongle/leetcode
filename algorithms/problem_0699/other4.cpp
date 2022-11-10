/*
  Similar to skyline concept, going from left to right the path is decomposed to
  consecutive segments, and each segment has a height. Each time we drop a new
  square, then update the level map by erasing & creating some new segments with
  possibly new height. There are at most 2n segments that are created / removed
  throughout the process, and the time complexity for each add/remove operation
  is O(log(n)).
 */

class Solution {
  public:
    vector<int> fallingSquares(vector<vector<int>> &p) {
        map<pair<int, int>, int> mp;
        mp[{0, 1000000000}] = 0;
        vector<int> ans;
        int mx = 0;
        for (auto &v : p) {
            vector<vector<int>> toAdd;
            int len = v[1], a = v[0], b = v[0] + v[1], h = 0;
            auto it = mp.upper_bound({a, a});
            if (it != mp.begin() && (--it)->first.second <= a)
                ++it;
            while (it != mp.end() && it->first.first < b) {
                if (a > it->first.first)
                    toAdd.push_back({it->first.first, a, it->second});
                if (b < it->first.second)
                    toAdd.push_back({b, it->first.second, it->second});
                h = max(h, it->second);
                it = mp.erase(it);
            }
            mp[{a, b}] = h + len;
            for (auto &t : toAdd)
                mp[{t[0], t[1]}] = t[2];
            mx = max(mx, h + len);
            ans.push_back(mx);
        }

        return ans;
    }
};
