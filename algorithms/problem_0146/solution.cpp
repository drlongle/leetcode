/*
46. LRU Cache

Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
*/

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <iostream>
#include <sstream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#include <string.h>

using namespace std;

struct Entry
{
    Entry(int k, int v) : key(k), value(v) { }
    int key;
    int value;
};

class LRUCache{
public:
    LRUCache(int capacity) {
        max_size = capacity; 
    }
   
    void insert(int key, int value)
    {
        values.emplace(values.begin(), key, value);
        lookup[key] = values.begin();
    }
 
    int get(int key) {
        map<int, list<Entry>::iterator>::iterator it;
        it = lookup.find(key);
        if (it == lookup.end()) return -1;
        int value = it->second->value;
        values.erase(it->second);
        insert(key, value);
        return value;
    }
    
    void set(int key, int value) {
        map<int, list<Entry>::iterator>::iterator it;
        it = lookup.find(key);
        if (it == lookup.end())
        {
            if (values.size() == max_size)
            {
                Entry e = values.back();
                values.pop_back();
                lookup.erase(e.key);
            }
        }
        else
            values.erase(it->second);
        insert(key, value);
    }

    void remove(list<Entry>::iterator it) 
    {
        lookup.erase(it->key);
        values.erase(it);
    }

    void print() const
    {
        for (const auto& v: values)
            cout << "key: " << v.key << ", value: " << v.value << endl;
    }

    size_t max_size;
    list<Entry> values;
    map<int, list<Entry>::iterator> lookup;
};

int main()
{
    LRUCache cache(19);
    int key, value;

    key = 1, value = 101;
    cache.set(key, value);
    key = 2, value = 102;
    cache.set(key, value);
    key = 3, value = 103;
    cache.set(key, value);
    key = 4, value = 104;
    cache.set(key, value);
    key = 5, value = 105;
    cache.set(key, value);
    key = 6, value = 106;
    cache.set(key, value);
    key = 2;
    value = cache.get(key);
    cout << key << " --> " << value << endl;
    key = 6;
    value = cache.get(key);
    cout << key << " --> " << value << endl;
    cache.print();

    return 0;
}
