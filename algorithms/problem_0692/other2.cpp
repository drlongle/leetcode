class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int>word_map;
        for (auto word : words) {
            word_map[word]++;
        }
        priority_queue<pair<string, int>, vector<pair<string, int>>,
                function<bool(pair<string, int>, pair<string, int>)>> pq(
                        [](const pair<string, int>& a, const pair<string, int>& b) {
            return a.second == b.second ? a.first < b.first : a.second >b.second;
        });
        for (auto ittr : word_map) {
            pq.push({ ittr.first,ittr.second });
            if (pq.size() > k)
                pq.pop();
        }
        vector<string>ans;
        while (!empty(pq)) {
            ans.emplace_back(pq.top().first);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
