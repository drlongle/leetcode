/*
1105. Filling Bookcase Shelves
Medium

We have a sequence of books: the i-th book has thickness books[i][0] and height books[i][1].
We want to place these books in order onto bookcase shelves that have total width shelf_width.
We choose some of the books to place on this shelf (such that the sum of their thickness
is <= shelf_width), then build another level of shelf of the bookcase so that the total
height of the bookcase has increased by the maximum height of the books we just put down.
We repeat this process until there are no more books to place.

Note again that at each step of the above process, the order of the books we place is
the same order as the given sequence of books.  For example, if we have an ordered list
of 5 books, we might place the first and second book onto the first shelf, the third book
on the second shelf, and the fourth and fifth book on the last shelf.

Return the minimum possible height that the total bookshelf can be after placing shelves
in this manner.
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

struct Key {
    Key(int i, int h, int w) : index(i), height(h), width(w)
    {
    }
    bool operator==(const Key& other) const
    {
        return index == other.index && height == other.height && width == other.width;
    }
    int index, height, width;
};

namespace std {
template <>
struct hash<Key> {
    size_t operator()(const Key& key) const
    {
        return key.index ^ key.height ^ key.width;
    }
};
} // namespace std

class Solution {
public:
    int arrange(vector<vector<int>>& books, int index, int height, int left_width)
    {
        if (index == nr_books)
            return height;
        Key key{index, height, left_width};
        auto it = cache.find(key);
        if (it != cache.end())
            return it->second;
        int res = height + arrange(books, index + 1, books[index][1], width - books[index][0]);

        if (left_width >= books[index][0]) {
            res = min(res, arrange(books, index + 1, max(height, books[index][1]), left_width - books[index][0]));
        }
        cache[key] = res;

        return res;
    }

    int minHeightShelves(vector<vector<int>>& books, int shelf_width)
    {
        width = shelf_width;
        nr_books = books.size();
        return arrange(books, 0, 0, 0);
    }

    unordered_map<Key, int> cache;
    int width, nr_books;
};

int main()
{
    Solution sol;
    vector<vector<int>> books;
    int width;

    // Expected: 6
    books = {{1, 1}, {2, 3}, {2, 3}, {1, 1}, {1, 1}, {1, 1}, {1, 2}}, width = 4;

    cout << "Result: " << sol.minHeightShelves(books, width) << endl;

    return 0;
}
