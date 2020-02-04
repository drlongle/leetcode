class Solution {
public:
    int minSetSize(vector<int>& arr) {
        std::unordered_map<int, int> counts;
        for (int v: arr) {
            counts.emplace(v, 0);
            ++counts[v];
        }
        
        std::priority_queue<int> Q;
        for (auto count: counts) {
            Q.push(count.second);
        }
        
        int N = arr.size();
        int target = N / 2;
        int setSize = 0;
        while (N > target) {
            N -= Q.top(); Q.pop();
            ++setSize;
        }
        
        return setSize;
    }
};
