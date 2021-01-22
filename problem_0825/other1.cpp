class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(), ages.end());
        int n = ages.size(), count = 0;
        for (int i = n - 1; i >= 0; i--) {
            int val = 0.5 * ages[i] + 7;
            int index = upper_bound(ages.begin(), ages.end(), val) - ages.begin();
            int c = 1, prev = i;
            while (i - 1 >= 0 && ages[i] == ages[i - 1]) {
                c++;
                i--;
            }
            if (index >= prev) continue;
            count += (prev - index) * c;
        }
        return count;
    }
};
