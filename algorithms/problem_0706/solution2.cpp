class MyHashMap {
public:

    static constexpr int size = 1000;
    vector<list<pair<int, int>>> buckets;

    MyHashMap(): buckets(size) {}

    /** value will always be non-negative. */
    void put(int key, int value) {
        auto& bucket = buckets[key % size];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                it->second = value;
                return;
            }
        }
        bucket.emplace(bucket.begin(), key, value);
    }

    /** Returns the value to which the specified key is mapped,
     * or -1 if this map contains no mapping for the key */
    int get(int key) {
        auto& bucket = buckets[key % size];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                return it->second;
            }
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        auto& bucket = buckets[key % size];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                return;
            }
        }
    }
};
