/*
Sort events according finish time in increasing way
Iterate over events and check each day in current event reserved by other event. If some day in current event is not reserved, then increment number of events and put that day into hash set. Hash set is necessary to check do we have event on that day or not. If there is no event on that day (no that day in hash set), we stop iterating on the current event.
Time Complexity: O(max(nlogn, n*d)) - d is the total number of days of all events
 */
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        if (events.size() == 0) {
            return 0;
        }
        sort(events.begin(), events.end(),
             [] (const vector<int> &p1, const vector<int> &p2) 
             {
                 return p1[1] < p2[1] || p1[1] == p2[1] && p1[0] < p2[0];
             }); // sort by ending day
        int result = 0;
        unordered_set<int> set; // hash set
        for (int i = 0; i < events.size(); i++) {
            for (int j = events[i][0]; j <= events[i][1]; j++) {
                if (set.count(j) == 0) { // if that day is not reserved, increment events
                    result++;
                    set.insert(j);
                    break;
                }
            }
        }
        return result;
    }
};
