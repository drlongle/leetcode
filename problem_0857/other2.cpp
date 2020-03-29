/*
We need two data, ratio and quality. We sort workers by the ratio of wage/quality from small to big. For the first K workers, we just add them to queue at first.
For following workers, whenever come a new worker, we will check the new ratio(always bigger than previous), and the new quality(maybe smaller by replace one "small ratio worker"). And we check the final answer, the current max ratio and current min quality.
Maybe after replace the max quality, we do not want to change workers we alreay have, but we do not need to take care of wrong replace. Because following ratio is always greater than previous one, so the min quality in queue, we can always have better answer than keep the "final best" queue.

I use two priority_queue to sort and keep track of quality.
*/

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        priority_queue<pair<double, int>, vector<pair<double, int>>, CustomCompare> q;
        for(int i = 0; i < wage.size(); i++)
            q.push(make_pair((double)wage[i]/(double)quality[i], quality[i]));
        priority_queue<int> pq;
        double qsum = 0;
        double res = DBL_MAX;
        while(!q.empty()){
            qsum += q.top().second;
            pq.push(q.top().second);
            
            if (pq.size() > K) qsum -= pq.top(), pq.pop();
            if (pq.size() == K) res = min(res, qsum * q.top().first);
            q.pop();
        }
        return res;
    }
    
private:
    struct CustomCompare{
        bool operator()(pair<double, int> &p1, pair<double, int> &p2){
            // if p1>p2 true, p1 is behind p2
            return p1.first > p2.first;
        }
    };

};
