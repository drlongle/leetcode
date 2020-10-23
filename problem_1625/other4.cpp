class Solution {
public:
    using Queue = queue<string>;
    using Set = unordered_set<string>;
    using fun = function<void(string)>;
    string findLexSmallestString(string s, int amount, int pivot) {
        auto best{ s };
        Queue q{{{ s }}};
        Set seen{ s };
        while (q.size()) {
            auto cur = q.front(); q.pop();
            if (best > cur)
                best = cur;
            string increment;
            transform(cur.begin(), cur.end(), back_inserter(increment), [i = -1, amount](auto c) mutable {
                return ++i & 1 ? (((c - '0') + amount) % 10) + '0' : c;
            });
            if (seen.insert(increment).second)
                q.push(increment);
            auto rotate = cur.substr(pivot) + cur.substr(0, pivot);
            if (seen.insert(rotate).second)
                q.push(rotate);
        }
        return best;
    }
};
