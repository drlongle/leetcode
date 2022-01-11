/*
 Merge sort

 Step 1: Initialize larger array and smaller array, which store the number of elements on
 left strictly larger and smaller than the current element, respectively.

 Step 2: Implement two merge sort function: sortLargerand sortSmaller.

 For sortLarger, we perform a stable merge sort. When merging, we record the number of elements
 jumping from left to right.

 For sortSmaller, we perform a totally unstable merge sort. When merging, we record the number
 of elements staying on left.

 Step 3: Iterate over instructions. For each element:
 Add the minimal of smaller[i] and larger[i] to the total cost.
 Update the element into the Binary Indexed Tree.
 Step 3: Return the total cost after iteration.
*/

class Solution {
    vector<int> smaller;
    vector<int> larger;

public:
    int createSortedArray(vector<int>& instructions) {
        int n = instructions.size();
        smaller.resize(n);
        larger.resize(n);
        // Note: raw array used here
        int temp[n][2]; // record some temporal information
        long cost = 0;
        long MOD = 1000000007;

        int arrSmaller[n][2];
        int arrLarger[n][2];

        for (int i = 0; i < n; i++) {
            arrSmaller[i][0] = instructions[i];
            arrSmaller[i][1] = i;
            arrLarger[i][0] = instructions[i];
            arrLarger[i][1] = i;
            smaller[i] = 0;
            larger[i] = 0;
        }

        sortSmaller(arrSmaller, 0, n - 1, temp);
        sortLarger(arrLarger, 0, n - 1, temp);

        for (int i = 0; i < n; i++) {
            cost += min(smaller[i], larger[i]);
            cost %= MOD;
        }
        return (int)(cost % MOD);
    }

    void sortSmaller(int arr[][2], int left, int right, int temp[][2]) {
        if (left == right) {
            return;
        }
        int mid = (left + right) / 2;
        sortSmaller(arr, left, mid, temp);
        sortSmaller(arr, mid + 1, right, temp);
        mergeSmaller(arr, left, right, mid, temp);
    }

    void mergeSmaller(int arr[][2], int left, int right, int mid,
                      int temp[][2]) {
        // merge [left, mid] and [mid+1, right]
        int i = left;
        int j = mid + 1;
        int k = left;
        // use temp[left...right] to temporarily store sorted array
        while (i <= mid && j <= right) {
            if (arr[i][0] < arr[j][0]) {
                temp[k][0] = arr[i][0];
                temp[k][1] = arr[i][1];
                k++;
                i++;
            } else {
                temp[k][0] = arr[j][0];
                temp[k][1] = arr[j][1];
                k++;
                smaller[arr[j][1]] += i - left;
                j++;
            }
        }
        while (i <= mid) {
            temp[k][0] = arr[i][0];
            temp[k][1] = arr[i][1];
            k++;
            i++;
        }
        while (j <= right) {
            temp[k][0] = arr[j][0];
            temp[k][1] = arr[j][1];
            k++;
            smaller[arr[j][1]] += i - left;
            j++;
        }
        // restore from temp
        for (i = left; i <= right; i++) {
            arr[i][0] = temp[i][0];
            arr[i][1] = temp[i][1];
        }
    }

    void sortLarger(int arr[][2], int left, int right, int temp[][2]) {
        if (left == right) {
            return;
        }
        int mid = (left + right) / 2;
        sortLarger(arr, left, mid, temp);
        sortLarger(arr, mid + 1, right, temp);
        mergeLarger(arr, left, right, mid, temp);
    }

    void mergeLarger(int arr[][2], int left, int right, int mid,
                     int temp[][2]) {
        // merge [left, mid] and [mid+1, right]
        int i = left;
        int j = mid + 1;
        int k = left;
        // use temp[left...right] to temporarily store sorted array
        while (i <= mid && j <= right) {
            if (arr[i][0] <= arr[j][0]) {
                temp[k][0] = arr[i][0];
                temp[k][1] = arr[i][1];
                k++;
                i++;
            } else {
                temp[k][0] = arr[j][0];
                temp[k][1] = arr[j][1];
                k++;
                larger[arr[j][1]] += mid - i + 1;
                j++;
            }
        }
        while (i <= mid) {
            temp[k][0] = arr[i][0];
            temp[k][1] = arr[i][1];
            k++;
            i++;
        }
        while (j <= right) {
            temp[k][0] = arr[j][0];
            temp[k][1] = arr[j][1];
            k++;
            larger[arr[j][1]] += mid - i + 1;
            j++;
        }
        // restore from temp
        for (i = left; i <= right; i++) {
            arr[i][0] = temp[i][0];
            arr[i][1] = temp[i][1];
        }
    }
};