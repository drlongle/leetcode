class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        set<int> ids;
        sort(rooms.begin(), rooms.end(), [](auto& a, auto& b){return a[1] > b[1];});
        priority_queue<tuple<int,int,int>> queryQ;
        const int n = queries.size();
        vector<int> res(n, -1);
        for(int i=0;i<queries.size();i++){
            int preferId = queries[i][0];
            int minSize = queries[i][1];
            queryQ.emplace(minSize, preferId, i);
        }
        
        auto it = rooms.begin();
        while(!queryQ.empty()){
            auto [minSize, preferId, i] = queryQ.top(); queryQ.pop();
            while(it != rooms.end() && it->at(1)>= minSize){
                ids.insert(it->at(0));
                it++;
            }
            
            auto it2 = ids.lower_bound(preferId);
            int ans = -1, minDis = 1e9;
            if(it2 != ids.end()){
                ans = *it2;
                minDis = abs(*it2 - preferId);
            }
            if(it2 != ids.begin()){
                auto pre = *prev(it2);
                if(preferId - pre <= minDis)
                    ans = pre;
            }
            res[i] = ans;
        }
        return res;
    }
};
