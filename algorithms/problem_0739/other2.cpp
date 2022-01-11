class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<pair<int, int>> s;
        vector<int> res(T.size(), 0);
        for(int i = 0; i < T.size(); i++){
            while(!s.empty() && s.top().first < T[i]){
                res[s.top().second] = i - s.top().second;
                s.pop();
            }
            s.push({T[i], i});
        }
        return res;
    }
};
