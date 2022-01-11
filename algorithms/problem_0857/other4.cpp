typedef pair<double, int> RPqItem;
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        priority_queue<RPqItem> rpq;
        priority_queue<int> qpq;
        for(int i = 0; i < quality.size(); ++ i){
            rpq.emplace(-(double)wage[i]/quality[i], i);
        }
        
        int point = 0;
        double maxr;
        while(K--){
            point += quality[rpq.top().second];
            maxr = -rpq.top().first;
            qpq.push(quality[rpq.top().second]);
            rpq.pop();
        }
        double res = maxr * point;
        
        while(!rpq.empty()){
            maxr = -rpq.top().first;
            int idx = rpq.top().second;
            rpq.pop();
            int minus = -qpq.top();
            qpq.pop();
            point += minus + quality[idx];
            res = min(res, point * maxr);
            
            qpq.push(quality[idx]);
        }
        
        return res;
    }
};
