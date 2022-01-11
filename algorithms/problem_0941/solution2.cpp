class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int sz = arr.size();
        if (sz < 3 || arr[0] >= arr[1])
            return false;
        bool up = true;
        for (int i = 1; i < sz; ++i) {
            if (arr[i] == arr[i-1])
                return false;
            if (up && arr[i] < arr[i-1])
                up = false;
            else if (!up && arr[i] > arr[i-1])
                return false;
        }

        return !up;
    }
};