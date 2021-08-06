class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int N)
    {
        sort(begin(logs), end(logs));
        vector uf(N, 1), n(N, 1);
        iota(begin(uf), end(uf), 0);

        for(auto r1{-1}, r2{-1}; const auto & l : logs)
        {
            for(r1 = l[1]; uf[r1] != r1; r1 = uf[r1]);
            for(r2 = l[2]; uf[r2] != r2; r2 = uf[r2]);
            if(uf[r1] = r2; r1 != r2 and (n[r2] += n[r1]) == N) return l[0];
        }

        return -1;
    }
};
