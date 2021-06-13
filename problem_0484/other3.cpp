class Solution {
public:
    using VI = vector<int>;
    VI findPermutation(string t, VI s = {}, VI ans = {}) {
        t.push_back('I');                               // sentinel value to exhaust last downslope xor append max value last
        for (auto i{ 0 }; i < t.size(); ++i) {
            s.push_back(i + 1);                         // +1 for 1-based indexing
            while (t[i] == 'I' && s.size())
                ans.push_back(s.back()), s.pop_back();  // greedily consume current upslope xor exhaust pending downslope
        }
        return ans;
    }
};
