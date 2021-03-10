class Solution {
public:
    vector<string> topKFrequent(vector<string>& nums, int k) {
        map<string, int> topK;
        for(int i = 0; i < nums.size(); i++)
            topK[nums.at(i)]++;

        multimap<int, string, greater<int>> topKElements;
        for(auto iter = topK.begin(); iter != topK.end(); iter++)
            topKElements.insert({iter->second, iter->first});

        vector<string> result;
        for(auto iter = topKElements.begin(); iter != topKElements.end(); iter++){
            if(k == 0) break;
            result.push_back(iter->second);
            k--;
        }

        return result;
    }
};