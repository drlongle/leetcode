class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(begin(arr), end(arr));
        int m = arr[(arr.size() -1) / 2], i = 0, j = arr.size() - 1;
        vector<int> res;
        while (res.size() < k)
            if (abs(arr[i] - m) > abs(arr[j] - m))
                res.push_back(arr[i++]);  
            else
                res.push_back(arr[j--]);
        return res;
    }
};
