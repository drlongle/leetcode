/*
1146. Snapshot Array
Medium

Implement a SnapshotArray that supports the following interface:

SnapshotArray(int length) initializes an array-like data structure with the given length.  Initially, each element
equals 0. void set(index, val) sets the element at the given index to be equal to val. int snap() takes a snapshot of
the array and returns the snap_id: the total number of times we called snap() minus 1. int get(index, snap_id) returns
the value at the given index, at the time we took the snapshot with the given snap_id

Example 1:

Input: ["SnapshotArray","set","snap","set","get"]
[[3],[0,5],[],[0,6],[0,0]]
Output: [null,null,0,null,5]
Explanation:
SnapshotArray snapshotArr = new SnapshotArray(3); // set the length to be 3
snapshotArr.set(0,5);  // Set array[0] = 5
snapshotArr.snap();  // Take a snapshot, return snap_id = 0
snapshotArr.set(0,6);
snapshotArr.get(0,0);  // Get the value of array[0] with snap_id = 0, return 5
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

struct Cell {
    Cell() : val(0)
    {
    }
    int val;
    vector<int> snapshots;
};

class SnapshotArray {
public:
    SnapshotArray(int length) : cells(length)
    {
    }

    void set(int index, int val)
    {
        dirty[index] = val;
    }

    int snap()
    {
        int snap_id = snapshots.size();
        for (auto& p : dirty)
            cells[p.first].snapshots.emplace_back(snap_id);
        snapshots.push_back(dirty);
        dirty.clear();

        return snap_id;
    }

    int get(int index, int snap_id)
    {
        Cell& cell = cells[index];

        int lo = 0, hi = cell.snapshots.size() - 1;
        int id = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (cell.snapshots[mid] <= snap_id) {
                id = mid;
                lo = mid + 1;
            } else
                hi = mid - 1;
        }

        if (id < 0)
            return cell.val;
        else
            return snapshots[cell.snapshots[id]][index];
    }

    vector<Cell> cells;
    vector<map<int, int>> snapshots;
    map<int, int> dirty;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */

void test_1()
{
    SnapshotArray array(10);
    for (int i = 0; i < 10; ++i) {
        array.set(3, i);
        array.snap();
    }

    for (int i = 0; i < 10; ++i) {
        cout << "snapshot: " << i << " -> " << array.get(3, i) << endl;
    }
}

void test_0()
{
    SnapshotArray snapshotArr(3); // set the length to be 3
    snapshotArr.set(0, 5);        // Set array[0] = 5
    snapshotArr.snap();           // Take a snapshot, return snap_id = 0
    snapshotArr.set(0, 6);
    auto val = snapshotArr.get(0, 0); // Get the value of array[0] with snap_id = 0, return 5
    cout << "val: " << val << endl;
}

void test_2()
{
    int nsize = 20;
    int rounds = 10;

    SnapshotArray array(nsize);
    int i = 0;
    for (int r = 0; r < rounds; ++r) {
        for (int n = 0; n < nsize; ++n) {
            array.set(n, i++);
        }
        array.snap();
    }

    for (int r = 0; r < rounds; ++r) {
        for (int n = 0; n < nsize; ++n) {
            cout << "round: " << r << ", index: " << n << " -> " << array.get(n, r) << endl;
        }
    }
}

/*
["SnapshotArray","snap","snap","set","snap","get","set","get","snap","get"]
[[1],[],[],[0,4],[],[0,1],[0,12],[0,1],[],[0,3]]
Expected: [null,0,1,null,2,0,null,0,3,12]
*/
void test_40()
{
    SnapshotArray array(1);
    cout << "null" << endl;

    cout << array.snap() << endl;

    cout << array.snap() << endl;

    cout << "null" << endl;
    array.set(0, 4);

    cout << array.snap() << endl;

    cout << array.get(0, 1) << endl;

    cout << "null" << endl;
    array.set(0, 12);

    cout << array.get(0, 1) << endl;

    cout << array.snap() << endl;

    cout << array.get(0, 3) << endl;
}

int main()
{
    // test_0();
    // test_1();
    // test_2();
    test_40();

    return 0;
}
