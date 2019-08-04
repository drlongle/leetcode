class Solution {
public:
    class pickupComparator {
    public:
        bool operator()(const vector<int>& tripA, const vector<int>& tripB)
        {
            if (tripA[1] == tripB[1])
                return tripA[2] > tripB[2];
            else
                return tripA[1] > tripB[1];
        }
    };

    class dropoffComparator {
    public:
        bool operator()(const vector<int>& tripA, const vector<int>& tripB)
        {
            if (tripA[2] == tripB[2])
                return tripA[1] > tripB[1];
            else
                return tripA[2] > tripB[2];
        }
    };

    bool carPooling(vector<vector<int>>& trips, int capacity)
    {
        priority_queue<vector<int>, vector<vector<int>>, pickupComparator> pickupQ;
        priority_queue<vector<int>, vector<vector<int>>, dropoffComparator> dropoffQ;

        for (int i = 0; i < trips.size(); i++) {
            pickupQ.push(trips[i]);
            dropoffQ.push(trips[i]);
        }

        int passengers = 0;
        while (!pickupQ.empty()) {
            while (!dropoffQ.empty() && pickupQ.top()[1] >= dropoffQ.top()[2]) {
                passengers -= dropoffQ.top()[0];
                dropoffQ.pop();
                cout << passengers << endl;
            }

            passengers += pickupQ.top()[0];
            pickupQ.pop();
            if (passengers > capacity)
                return false;
        }

        return true;
    }
};
