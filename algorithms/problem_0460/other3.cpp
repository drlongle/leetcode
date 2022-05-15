class LFUCache {
public:

    class LFUList {

    public:
        LFUList(int useCount) : useCount(useCount) {

        }

        list<int> lru;
        int useCount;
    };

    class Location {

    public:
        Location() {}
        Location(list<LFUList>::iterator lfuIt, list<int>::iterator lruIt) :
                lfuIt(lfuIt), lruIt(lruIt) {

        }

        list<LFUList>::iterator lfuIt;
        list<int>::iterator lruIt;
    };

    LFUCache(int capacity) : capacity(capacity) {
        tbl.reserve(capacity);
    }

    void updateUseCount(list<LFUList>::iterator lfuElement, list<int>::iterator lruElement, unordered_map<int, pair<int, Location>>::iterator tblIt) {
        int key = (*lruElement);
        auto &lfuList = *(lfuElement);

        lfuList.lru.erase(lruElement);

        auto nxt = next(lfuElement);
        if (nxt == lfu.end() || (*nxt).useCount > lfuList.useCount + 1) {
            /* use_count+1 lfu doesn't exist, need to create it */
            auto newLfu = lfu.emplace(nxt, lfuList.useCount + 1);
            nxt = newLfu;
            (*newLfu).lru.push_back(key);
        }
        else {
            /* use_count+1 lfu exists, push back to it */
            (*nxt).lru.push_back(key);
        }

        if (lfuList.lru.empty() && (*minUseCountList).useCount == lfuList.useCount) {
            /* we emptied the lru and it was the one referenced by the minUseCountList, so need to update it */
            minUseCountList = next(lfuElement);
            lfu.erase(lfuElement);
        }

        // update iterators in tbl
        auto &tblVal = tblIt->second;
        tblVal.second.lfuIt = nxt;
        tblVal.second.lruIt = prev((*nxt).lru.end());
    }

    int get(int key) {
        int uc;
        auto it = tbl.find(key);

        if (it == tbl.end()) {
            return -1;
        }

        updateUseCount(it->second.second.lfuIt, it->second.second.lruIt, it);

        return it->second.first;
    }

    void put(int key, int value) {

        if (__builtin_expect((capacity == 0), 0))
            return;

        auto it = tbl.find(key);

        if (it != tbl.end()) {
            /* key exists, just update value and use count */
            auto &val = it->second;
            val.first = value;
            updateUseCount(val.second.lfuIt, val.second.lruIt, it);
        }
        else {
            /* key doesn't exist, evict if needed */
            if (tbl.size() == capacity) {
                /* evict */
                auto& evctCand = (*minUseCountList).lru.front();
                tbl.erase(evctCand);
                (*minUseCountList).lru.pop_front();
                /* lru could've been emptied, need to remove it from the lfu list,
                   later we will anyway update the min to point to use_count=1 list */
                if ((*minUseCountList).lru.empty()) {
                    lfu.erase(minUseCountList);
                }
            }

            if (lfu.empty() || lfu.front().useCount > 1) {
                /* we need to create a new list to hold our new element with use_count=1 */
                lfu.emplace_front(1);
                minUseCountList = lfu.begin();
            }
            lfu.front().lru.push_back(key);

            auto [it, ok] = tbl.insert({key, {value, Location(lfu.begin(), prev(lfu.front().lru.end()))}});
        }
    }

    list<LFUList>::iterator minUseCountList;
    int capacity;
    unordered_map<int, pair<int, Location>> tbl;
    list<LFUList> lfu;
};
