class comFunction {
public:
    int operator()(pair<int,string> &a, pair<int,string> &b){
        if(a.first==b.first) {
            return a.second.compare(b.second)<0;
        }
        return a.first>b.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for(auto word: words){
            m[word] += 1;
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, comFunction> minH;
        for(auto i=m.begin();i!=m.end();i++){
            minH.push({i->second, i->first});
            if(minH.size()>k) minH.pop();
        }
        vector<string> out;
        while(!minH.empty()){
            out.push_back(minH.top().second);
            minH.pop();
        }
        reverse(out.begin(),out.end());
        return out;
    }
};
