class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        /// w[0] / q[0] = w[1] / q[1] = w[2] / q[2] .. = w[i] / q[i] = x
        int n = quality.size() ;
        vector<pair<double,int> > v ;
        for(int i = 0 ; i < n ; ++i) {
            double foo = (double)wage[i] / quality[i] ;
            v.push_back({foo , quality[i]});
        }
        sort(v.begin() , v.end()) ;
        double sum = 0 , ans= 0;
        priority_queue<int> pq ;
        for(int i = 0 ; i < K ; ++i) {
            sum = sum + v[i].second ;
            pq.push(v[i].second) ;
        }
        ans = sum * v[K-1].first ;
        
        for(int i = K ; i < n ; ++i) {
            int maxquality = pq.top() ;
            int curr = v[i].second ;
            if(maxquality > curr) {
                pq.pop() ;
                pq.push(curr) ;
                sum = sum + curr - maxquality ;
            }
            double res = sum * v[i].first;
            ans = min(ans , sum * v[i].first) ;
        }
        return ans ;
    }
};
