class Solution {
public:
    using Set = unordered_set<string>;
    using fun = function<void(string)>;
    string findLexSmallestString(string s, int amount, int pivot) {
        auto best{ s };
        Set seen{ s };
        fun go = [&](auto s) {
            if (best > s)
                best = s;
            string increment;
            transform(s.begin(), s.end(), back_inserter(increment), [i = -1, amount](auto c) mutable {
                return ++i & 1 ? (((c - '0') + amount) % 10) + '0' : c;
            });
            if (seen.insert(increment).second)
                go(increment);
            auto rotate = s.substr(pivot) + s.substr(0, pivot);
            if (seen.insert(rotate).second)
                go(rotate);
        };
        go(s);
        return best;
    }
};
