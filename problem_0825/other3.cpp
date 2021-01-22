class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        // build age frequency
        unordered_map<int, int> fre;
        for (int age : ages)
            if (age >= 15) fre[age]++; // people younger than 15 don't request (by requirement)

        int cnt = 0;
        for (auto& p1 : fre)
            for (auto& p2 : fre) {
                int age1 = p1.first, age2 = p2.first;
                if (request(age1, age2)) cnt += p1.second*p2.second;
                if (age1 == age2) cnt -= p1.second; // remove "self reuqest"
            }

        return cnt;
    }

private:
    // age1 requests age2 iff age2 <= age1 < 2*age2 - 14
    bool request(int age1, int age2) {
        return age2 <= age1 && age1 < 2*age2 - 14;
    }
};
