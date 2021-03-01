class Solution {
public:
    vector<int> minOperations(string bs) {
        int n = bs.size();

        // We use l[i] to record there are how many 1s before index i
        // and r[i] to record there are how many 1s after index i, including i.
        vector<int> l(n, 0), r(n + 1, 0), ans(n, 0);

        // Initialisation of l
        // With out loss of generality, we can count the answer for index 0 and deduce
        // other answers based on answer[0]. We count answer[0] simultaneously here.
        for(int i = 1; i < n; i++)
        {
            if(bs[i-1] == '1')
            {
                l[i] = l[i-1] + 1;
                ans[0] += i-1;
            }
            else
                l[i] = l[i-1];
        }
        if(bs[n-1] == '1')ans[0] += n - 1;

        // Initialisation of r
        for(int i = n - 1; i >= 0; i --)
        {
            if(bs[i] == '1') r[i] = r[i+1] + 1;
            else r[i] = r[i+1];
        }

        for(int i = 1; i < n; i++)
        {
            ans[i] = ans[i - 1] + l[i] - r[i];
        }

        return ans;
    }
};
