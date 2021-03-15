class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int i = arr.size() - 2;
        while (i >= 0 && arr[i] <= arr[i + 1]) i--;

        if (i >= 0) {
            int j = arr.size() - 1;
            while (arr[j] >= arr[i]) j--;
            while (arr[j] == arr[j - 1]) j--;
            swap(arr[j], arr[i]);
        }
        return arr;
    }
};
