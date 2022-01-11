class Solution {
public:
    int countStudents(vector<int>& studs, vector<int>& sands) {
        // support variables
        int counter[2] = {}, len = studs.size(), sandPos = 0;
        // populating counter
        for (int n: studs) counter[n]++;
        // main loop
        for (int n: sands) {
            // 1st case: there are still students demanding it
            if (counter[n]) {
                counter[n]--;
                sandPos++;
            }
                // 2nd case: there are no more students demanding it
            else break;
        }
        return len - sandPos;
    }
};
