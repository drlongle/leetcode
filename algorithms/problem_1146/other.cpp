/*
It's similar to 981. Time Based Key-Value Store.

Note that we can achieve O(1) complexity for the get operation, but it won't
be memory-efficient if we pre=populate our store and then make a lot of snaps
(without modifying much).
*/

class SnapshotArray {
    unordered_map<int, map<int, int>> a;
    int cur_snap = 0;
    int snap()
    {
        return cur_snap++;
    }
    void set(int index, int val)
    {
        a[index][cur_snap] = val;
    }
    int get(int index, int snap_id)
    {
        auto it = a[index].upper_bound(snap_id);
        return it == begin(a[index]) ? 0 : prev(it)->second;
    }
};

/*
Since our timestamps are only increasing, we can use a vector instead of a map,
though it's not as concise.
*/
class SnapshotArray {
    unordered_map<int, vector<pair<int, int>>> m;
    int cur_snap = 0;
    int snap()
    {
        return cur_snap++;
    }
    void set(int index, int val)
    {
        if (m[index].empty() || m[index].back().first != cur_snap)
            m[index].push_back({cur_snap, val});
        else
            m[index].back().second = val;
    }
    int get(int index, int snap_id)
    {
        auto it = upper_bound(begin(m[index]), end(m[index]), pair<int, int>(snap_id, INT_MAX));
        return it == begin(m[index]) ? 0 : prev(it)->second;
    }
};
