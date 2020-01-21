// Reused the solution from 1024. Video Stitching.

class Solution {
public:
    int minTaps(int n, vector<int>& rs) {
        vector<vector<int>> clips;
        for (auto i = 0; i < rs.size(); ++i) {
            clips.push_back({i - rs[i], i + rs[i]});
        }
        return videoStitching(clips, n);
    }
    int videoStitching(vector<vector<int>>& clips, int T, int res = 0) {
        sort(begin(clips), end(clips));
        for (auto i = 0, st = 0, end = 0; st < T; st = end, ++res) {
            while (i < clips.size() && clips[i][0] <= st) 
                end = max(end, clips[i++][1]);
            if (st == end) return -1;
        }
        return res;
    }
};
