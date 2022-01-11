class Solution {
    int find(int root, vector<int> &pre) {
        if (root == pre[root]) return root;
        int son = root;
        int tmp;
        while (root != pre[root]) {
            root = pre[root];
        }
        while (son != root) {
            tmp = pre[son];
            pre[son] = root;
            son = tmp;
        }
        return root;
    }

public:
    int largestComponentSize(vector<int>& A) {
        vector<vector<int>> factored(A.size());
        for (int i = 0; i < A.size(); i++) {
            int d = 2, x = A[i];
            while (d*d <= x) {
                if (x%d == 0) {
                    while (x%d == 0) {
                        x /= d;
                    }
                    factored[i].push_back(d);
                }
                d++;
            }
            if (x > 1 || factored[i].size()==0) factored[i].push_back(x);
        }
        unordered_map<int, int> primes;
        int t = 0;
        for (auto vec : factored) {
            for (int v : vec) {
                if (!primes.count(v)) {
                    primes[v] = t;
                    t++;
                }
            }
        }
        vector<int> pre(primes.size());
        for (int i = 0; i < pre.size(); i++) {
            pre[i] = i;
        }
        for (int i = 0; i < A.size(); i++) {
            if (factored[i].size() < 2) continue;
            for (int j = 1; j < factored[i].size(); j++) {
                pre[find(primes[factored[i][j]], pre)] = find(primes[factored[i][0]], pre);
            }
        }
        unordered_map<int, int> count;
        for (int i = 0; i < A.size(); i++) {
            int root = find(primes[factored[i][0]], pre);
            if (count.count(root)) count[root] += 1;
            else count[root] = 1;
        }
        int lcs = 0;
        for (auto it=count.begin(); it!=count.end(); it++) {
            lcs = max(lcs, it->second);
        }
        return lcs;
    }
};
