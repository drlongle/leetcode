class Solution {

public:
    int minBuildTime(vector<int>& blocks, int split) {

        priority_queue<int, vector<int>, greater<int>> pq;
        for(int e: blocks) pq.push(e);
        while(pq.size() >= 2){
            int a = pq.top();pq.pop();
            int b = pq.top(); pq.pop();
            pq.push(b + split);
        }
        return pq.top();
    }
};
