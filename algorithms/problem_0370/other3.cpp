class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> arr(length, 0);
        if(updates.size() == 0)
            return arr;

        sort(updates.begin(), updates.end());
        int diff=0, i=0, j=0, n=updates.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq; // Min Heap

        // Start setting array values as diff from index 0
        while(i < length) {
            // If our current index is greater than the end of a range, subtract
            // that range's value from diff
            while(!pq.empty() && pq.top().first < i) {
                diff -= pq.top().second;
                pq.pop();
            }

            // If a new range starts at my current index, I'll add it to diff and push the
            // range's end to the Min Heap
            while(j < n && updates[j][0] == i) {
                diff += updates[j][2];
                pq.push(make_pair(updates[j][1], updates[j][2]));
                j++;
            }
            arr[i++] = diff;
        }

        return arr;
    }
};
