class Solution {
public:
    vector<int> mostCompetitive(vector<int>& n, int k) {
        vector<int>s;
        for(auto i = 0; i < n.size(); i++) {
            while(!s.empty() && s.back() > n[i] && s.size() + n.size() - i > k)
                s.pop_back();
            if(s.size() < k)
                s.push_back(n[i]);
        }
        return s;
    }
};
