class Solution {
public:

    class Info {
    public:
        Info(int wi_, int bi_, int d_) {
            wi = wi_;
            bi = bi_;
            d = d_;
        }
        int wi;
        int bi;
        int d;
    };

    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {

        vector<Info> infos;
        for (int w = 0 ; w < workers.size(); ++w) {
            for (int b = 0; b < bikes.size(); ++b) {
                int d = abs(workers[w][0] - bikes[b][0]) + abs(workers[w][1] - bikes[b][1]);
                infos.push_back(Info(w, b, d));
            }
        }
        sort(infos.begin(), infos.end(), [](const auto& a, const auto& b) {
            if (a.d != b.d)
                return a.d < b.d;
            if (a.wi != b.wi)
                return a.wi < b.wi;
            return a.bi < b.bi;
        });
        vector<int> ans(workers.size(), -1);
        vector<bool> assigned(bikes.size(), false);
        for (auto& i : infos) {
            if (ans[i.wi] == -1 && !assigned[i.bi]) {
                ans[i.wi] = i.bi;
                assigned[i.bi] = true;
            }
        }
        return ans;
    }
};
