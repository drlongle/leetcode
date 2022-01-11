/*
open a vector P to record the number idx.

when n = 5
initialization:
1, 2, 3, 4, 5
P = {0,1,2,3,4};

Query number i, record P[i - 1] to answer.
Then all the number in P < P[i - 1] will plus 1; P[i - 1] turns to be 0;

e.g. query 3;
P = {1,2,0,3,4};
*/

class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> ans;
        vector<int> P(m, 1);
        for (int i = 0; i < m; ++i) {
            P[i] = i;
        }
        for (int i = 0; i < queries.size(); ++i) {
            int idx = P[queries[i] - 1];
            ans.push_back(idx);
            for (int j = 0; j < m; ++j) {
                if (P[j] < idx) ++P[j];
            }
            P[queries[i] - 1] = 0;
        }
        return ans;
    }
};
