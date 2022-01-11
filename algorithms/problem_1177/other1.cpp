/*
We care only about the parity of the character sum in the substring, so there is no need to do the full counting.

The __builtin_popcount() function is for g++ only. For C++20 use popcount(). For other compilers use
bitset<26>().count().
*/

vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries)
{
    int mask = 0;
    vector<int> ps(1);
    for (char c : s)
        ps.emplace_back(mask ^= 1 << (c - 'a'));

    vector<bool> r;
    for (auto& q : queries) {
        int odds = __builtin_popcount(ps[q[1] + 1] ^ ps[q[0]]);
        r.emplace_back(q[2] * 2 >= odds - (q[1] - q[0] + 1) % 2);
    }
    return r;
}
