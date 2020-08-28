/*
Let ok be a set of parent representatives with cardinality equal-to target T. Continually update the last step
while ok contains at least one parent representative. Update the parent representatives' length when sets are
joined and delete parent representatives which are ok but adjacent to the next i-th value of A under consideration,
ie. if a parent representative adjacent to i had length equal to target T before the i-th bit was set, then
that representative set's length is not equal-to target T after the i-th bit was set.
*/

class Solution {
public:
    using VI = vector<int>;
    using Set = unordered_set<int>;
    using fun = function<int(int)>;
    int findLatestStep(VI& A, int T, Set seen = {}, Set ok = {}, int last = -1) {
        transform(A.begin(), A.end(), A.begin(), [](auto i) { return i - 1; });   // ⭐️ -1 for 0-based indexing
        int N = A.size();
        VI P(N); iota(P.begin(), P.end(), 0);   // parent representative sets
        VI L(N, 1);                             // length of each representative set
        fun find = [&](auto x) {
            return P[x] = x == P[x] ? P[x] : find(P[x]);
        };
        auto _union = [&](auto a, auto b) {
            a = find(a);
            b = find(b);
            P[b] = a;                           // arbitrary choice for parent representative
            return L[a] + L[b];
        };
        auto step{ 1 };
        for (auto i: A) {
            seen.insert(i);
            if (0 < i)     ok.erase(find(P[i - 1]));
            if (i + 1 < N) ok.erase(find(P[i + 1]));
            if (seen.find(i - 1) != seen.end()) L[i] = _union(i, i - 1);
            if (seen.find(i + 1) != seen.end()) L[i] = _union(i, i + 1);
            if (L[i] == T)
                ok.insert(i);                  // ✅ i is the parent representative of the set with target T length
            if (ok.size())
                last = step;
            ++step;
        }
        return last;
    }
};
