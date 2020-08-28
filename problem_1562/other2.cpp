/*
Start from the back, insert the position of 0s.
An insertion creates two new islands of 1s. If any of them has length m, you're done.
*/

class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        if(m == n) return n;
        set<int> st{0, n+1};
        for(int i=n-1; i>=0; i--) {
            auto it = st.insert(arr[i]).first;
            if(((*it - *prev(it) - 1) == m) || ((*next(it) - *it - 1) == m)) return i;
        }
        return -1;
    }
};
