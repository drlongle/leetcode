class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    using Set = unordered_set<int>;
    int maxCandies(VI& unlocked, VI& candies, VVI& keys, VVI& has, VI& init, Set seen = {}, Set explored = {}, int total = 0) {
        for (queue<int> q{{init.begin(), init.end()}}; !q.empty(); q.pop()) {
            auto i = q.front();
            seen.insert(i);
            if (!unlocked[i] || !explored.insert(i).second)
                continue; // skip if i-th box is locked or already explored once
            total += candies[i];
            for (auto j: keys[i]) {
                unlocked[j] = 1; // immediately unlock j-th box with key
                if (seen.find(j) != seen.end() && explored.find(j) == explored.end())
                    q.push(j); // we have seen this j-th box, but did *not* have a key when we saw it
            }
            for (auto j: has[i])
                q.push(j); // add all contained boxes to queue for processing
        }
        return total;
    }
};
