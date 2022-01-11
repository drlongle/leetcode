
#include <iostream>
#include <map>
#include <vector>

// iterate from end. Use map.upper_bound to find the proper group, and divide the group into two.

using namespace std;

class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {

        int n = arr.size();
        map<int, int> mp; // represents the contiguous intervals of 1
        if(m > n) return -1;

        if(m==n) return n;

        mp[0] = n-1; //original all ones. We'll reach this state after we have traversed all elements of arr.

        for(int i = n - 1; i >= 0; i--) {
            int t = arr[i] - 1;
            auto it = prev(mp.upper_bound(t));

            // prev(it) returns less than or equal to t;
            //since we set mp[0], so prev() should always be valid;
            auto key = it->first;
            auto val = it->second;
            //we have to save it->second, since in later, it->second will change

            //break the group [kay, val] into [key t-1] [t +1 val]
            if(key < t) {
                mp[key] = t - 1;
            }
            mp[t+1] = val;

            if(val - t == m || t - key == m) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> arr;
    int m;

    // Output: 4
    arr = {3,5,1,2,4}, m = 1;
    cout << sol.findLatestStep(arr, m) << endl;

    // Output: -1
    arr = {3,1,5,4,2}, m = 2;
    cout << sol.findLatestStep(arr, m) << endl;

    // Output: 1
    arr = {1}, m = 1;
    cout << sol.findLatestStep(arr, m) << endl;

    // Output: 2
    arr = {2,1}, m = 2;
    cout << sol.findLatestStep(arr, m) << endl;

    // Output: 9
    arr = {3,2,5,6,10,8,9,4,1,7}, m = 3;
    cout << sol.findLatestStep(arr, m) << endl;

    return 0;
}
