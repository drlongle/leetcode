class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size(), left, right = 0;
        vector<int> res;

        // find right closest index
        while (right < n && arr[right] <= x) {
            right++;
        }

        left = right - 1;

        // collect k elements
        while (k-- > 0) {
            if (left < 0) res.push_back(arr[right++]); // left -> out of bound
            else if (right >= n) res.insert(res.begin(), arr[left--]); // right -> out of bound
            else { // both are within bound, pick the smaller one
                if (x - arr[left] <= arr[right] - x)
                    res.insert(res.begin(), arr[left--]);
                else
                    res.push_back(arr[right++]);
            }
        }
        return res;
    }
};
