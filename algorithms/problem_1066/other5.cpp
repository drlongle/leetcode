/* Solution should be a greedy approach to minimize the total distance b/w workers and bikes
   Using bitmask for assigned bikes build a priority queue and pick the min value
   to process next, when we find a pq ele with all workers assigned bikes for we know we have the
   answer as we are using a minHeap to process the smallest total first.
*/
// This is to represent the state of pqEle -> allocated bikes bitmap, workerId to allocate a
// bike next and total distance for currently mapped bikes and workers represented by this
// state
class State {
public:
    State(uint16_t bikeState, int workerId, uint32_t dist) {
        mBikeState = bikeState;
        mWorkerId = workerId;
        mDist = dist;
    }

    uint16_t mBikeState;     // bike bit-map indicating in-use bikes with '1'
    int  mWorkerId;          // WorkerId to assign a bike for
    uint32_t mDist;          // Total distance for mapped workers and bikes reperesented by current state
};

class ComparePQEle {
public:
    bool operator() (const State& ele1, const State& ele2) {
        return (ele1.mDist > ele2.mDist);
    }
};

// min priority queue..
typedef priority_queue<State, vector<State>, ComparePQEle> pq_t;

class Solution {
public:
    int getDistance(vector<int>& worker, vector<int>& bike) {
        return (abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]));
    }

    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        pq_t pq;

        // There could be duplicate states  to avoid duplicate work create a set of seen states
        unordered_set<string> hashSet;

        // insert initial ele with workerId to find bike for 0,
        // bikeState 0 -> no bikes assigned to any worker
        // start dist  = 0
        pq.push({0, 0, 0});

        while (!pq.empty()) {
            State ele = pq.top();
            pq.pop();

            if (ele.mWorkerId ==  workers.size()) {
                return ele.mDist;
            }

            string state = to_string(ele.mWorkerId) + "bike_state" + to_string(ele.mBikeState);
            if (hashSet.find(state) != hashSet.end()) {
                continue; // previously seen state skip computation
            }
            hashSet.insert(state); // insert current state into hashSet

            for (int b = 0; b < bikes.size(); b++) {
                // try and map all the available bikes to current worker and add a
                // state element to priority queue for each combination
                if ((ele.mBikeState & (1 << b)) == 0) {
                    // found a free bike add an element with this worker and bike pair to the queue
                    // increment the worker id
                    pq.push({(uint16_t)(ele.mBikeState | (1 << b)), ele.mWorkerId + 1, ele.mDist + getDistance(workers[ele.mWorkerId], bikes[b])});
                }
            }
        }

        return -1;
    }
};
