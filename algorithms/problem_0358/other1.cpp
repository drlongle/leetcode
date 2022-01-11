class Solution {
public:
    string rearrangeString(string s, int k) {
        if(k <= 1) return s;
        string res = "";
        unordered_map<char, int> map;
        queue<pair<int, char>> q;
        priority_queue<pair<int, char>> pq;
        for(char c : s) map[c]++;
        for(auto it = map.begin(); it != map.end(); it++){
            pq.push(make_pair(it->second, it->first));
        }
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            res += curr.second;
            curr.first--;
            q.push(curr);
            if(q.size() == k){
                auto f = q.front();
                if(f.first > 0) pq.push(q.front());
                q.pop();
            }
        }
        return res.size() == s.length() ? res : "";
    }
};
