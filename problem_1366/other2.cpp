class Solution {
public:
    string rankTeams(vector<string>& votes) {
        vector<vector<int> >  cnt(26, vector<int>(1001));
        for(auto &v :votes) {
            for(int i = 0; i < v.size(); ++i) {
                int c = v[i] - 'A';
                cnt[c][i]++;
                cnt[c][1000] = -c-1;
            }
        }
        sort(cnt.begin(), cnt.end(), [](auto &a, auto &b){
            for(int i = 0; i < a.size() && i < b.size(); ++i) {
                if(a[i] != b[i]) return a[i] > b[i];
            }
            return a.back() < b.back();
        });
        string ans;
        for(auto x :cnt) {
            if (x.back() != 0) ans.push_back((-x.back()) + 'A' - 1);
        }
        return ans;
    }
};
