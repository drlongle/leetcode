/*
Store indexes in increasing order for each unique element. For query, loop
through unique elements and check the number of indices between left and right
using the binary search.
*/

unordered_map<int, vector<int>> idx;
MajorityChecker(vector<int> &arr) {
    for (auto i = 0; i < arr.size(); ++i) idx[arr[i]].push_back(i);
}
int query(int left, int right, int threshold) {
    for (auto &i : idx) {
        if (i.second.size() < threshold) continue;
        auto it1 = lower_bound(begin(i.second), end(i.second), left);
        auto it2 = upper_bound(begin(i.second), end(i.second), right);
        if (it2 - it1 >= threshold) return i.first;
    }
    return -1;
}

/*
Runtime Optimization - Frequency
We can process unique elements from the most to least frequent. That way, we
have better chances bumping into the majority element sooner. Also, we can exit
as soon as the element size is less than the threshold.

With this optimization, the runtime improves from 328 to 160 ms.
 */

vector<pair<int, vector<int>>> idx;
MajorityChecker(vector<int> &arr) {
    unordered_map<int, vector<int>> m;
    for (auto i = 0; i < arr.size(); ++i) m[arr[i]].push_back(i);
    for (auto &p : m) idx.push_back({p.first, p.second});
    sort(begin(idx), end(idx), [](auto &p1, auto &p2) {
        return p1.second.size() > p2.second.size();
    });
}
int query(int left, int right, int threshold) {
    for (auto &i : idx) {
        if (i.second.size() < threshold) break;
        auto it1 = lower_bound(begin(i.second), end(i.second), left);
        auto it2 = upper_bound(begin(i.second), end(i.second), right);
        if (it2 - it1 >= threshold) return i.first;
    }
    return -1;
}
