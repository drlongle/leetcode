class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        int max_1 = INT_MIN;

        for(int i = 0; i < n; i++)
        {
            vector<int> sum(m);
            for(int j = i; j < n; j++)
            {
                for(int k = 0; k < m; k++)
                {
                    sum[k] += matrix[j][k];
                }
                set<int> curr;

                int currsum = 0;
                curr.insert(0);

                for(int j = 0; j < m; j++)
                {
                    currsum += sum[j];
                    auto iterator = curr.lower_bound(currsum - k);
                    if (iterator != curr.end())
                        max_1 = max(max_1, currsum - *iterator);
                    curr.insert(currsum);
                }
            }
        }

        return max_1;
    }
};