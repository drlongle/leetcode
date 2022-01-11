
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        double res = numeric_limits<double>::max();
        vector<Worker> workers;
        for(int i = 0; i < quality.size(); i++)
            workers.emplace_back(Worker(quality[i], wage[i]));

         // SORT BY UNIT COST!!!!
        sort(workers.begin(), workers.end());
        // MAX heap store by quality as we want to hire K smaller quality workers;
        priority_queue<int, vector<int>, less<int>> pq;
        int sum_quality = 0;
        for(const Worker& w: workers) { 
            pq.push(w.quality);
            sum_quality += w.quality;
            if(pq.size() > K) {
                sum_quality -= pq.top();
                pq.pop();
            }
            if(pq.size() == K)
                res = min(res, w.unit_cost * sum_quality);
        }
        return res;
        
    }

private:
    struct Worker {
        int quality;
        int wages;
        double unit_cost; // That's the unit cost 
        Worker(int q, int w): quality(q), wages(w), unit_cost((double)(w)/(double)(q)) {};
        bool operator<(const Worker&other) const {
            return unit_cost < other.unit_cost;
        }
    };
};
