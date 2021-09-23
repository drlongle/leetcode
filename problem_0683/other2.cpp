class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int K) {
        // Hash set to store the indices
        unordered_set<int> s;
        int n = bulbs.size();
        int i = 0;

        while (i < n) {
            int bidx = bulbs[i];
            // Find if bulb# bidx + k + 1 OR bidx - k - 1 is lighted
            // AND
            // there's no lighted bulb in between bidx and one of the above listed bulb #s
            if ((s.count(bidx + K + 1) > 0) || (s.count(bidx - K - 1) > 0)) {

                int j = s.count(bidx - K - 1) > 0 ? bidx - K : bidx + 1;
                int k = s.count(bidx - K - 1) > 0 ? bidx - 1 : bidx + K;
                bool lighted = false;

                while (j <= k) {
                    if (s.count(j) > 0) {
                        lighted = true;
                        break;
                    }
                    j++;
                }

                if (lighted) {
                    s.insert(bulbs[i]);
                    i++;
                    continue;
                }

                return i + 1;
            }
            // Add the lighted buld in hash set
            s.insert(bulbs[i]);
            i++;
        }

        return -1;
    }
};