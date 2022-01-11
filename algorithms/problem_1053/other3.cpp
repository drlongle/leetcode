class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();
        for (int i = n - 2; i >= 0; --i) {
            int temp_value = arr[i + 1];
            int pos = -1;
            for (int j = i + 1; j < n; ++j) {
                if (arr[j] < arr[i] && (arr[j] > temp_value || j == i + 1)) {
                    temp_value = arr[j];
                    pos = j;
                }
            }
            if (pos != -1) {
                arr[pos] = arr[i];
                arr[i] = temp_value;
                return arr;
            }
        }

        return arr;
    }
};
