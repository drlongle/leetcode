class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        // Starting from the last element, we move towards the head until arr[i] > arr[i + 1].
        // We then move from j = i + 1 to the end until arr[j] is the 1st maximum element less than arr[i].
        int i = arr.size() - 2;
        while (i >= 0 && arr[i] <= arr[i + 1])
        {
            --i;
        }

        if (i < 0)
        {
            return arr; // smallest already
        }

        int j = i + 1;
        for (int k = j; k < arr.size() && arr[k] < arr[i]; ++k)
        {
            j = arr[k] > arr[j] ? k : j; // find the maximum element < arr[i]
        }

        swap(arr[i], arr[j]);
        return arr;
    }
};
