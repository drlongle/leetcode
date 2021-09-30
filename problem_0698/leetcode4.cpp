/*
Algorithm

1. Calculate totalArraySum, and check if the sum is evenly divisible by k. If so, we can break the array
into k subsets and the sum of each subset must be equal targetSum = totalArraySum / k.

2. For each valid mask state:
- Iterate over each element in the array, and pick a not picked element if the sum will not exceed targetSum.
- Mark the element as picked in the mask and store the subset's sum at subsetSum[new_mask].
- new_mask will be the previous mask ORed with the current picked index, i.e. mask | (1<<i).
- It will make a new state valid and this state can be used in the future to add more elements to it.
3. If we reached the last dp state, i.e. 1111....111, then it means we can partition all the elements
in k subsets of the equal sum.
*/

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& arr, int k) {
        int totalArraySum = 0;
        int n = arr.size();

        for (int i = 0; i < n; ++i) {
            totalArraySum += arr[i];
        }

        // If total sum not divisible by k, we can't make subsets.
        if (totalArraySum % k != 0) {
            return false;
        }

        int targetSum = totalArraySum / k;

        vector<int> subsetSum((1 << n), -1);
        // Initially only one state is valid, i.e don't pick anything.
        subsetSum[0] = 0;

        for (int mask = 0; mask < (1 << n); mask++) {
            // If the current state has not been reached earlier.
            if (subsetSum[mask] == -1) continue;

            for (int i = 0; i < n; i++) {
                // If the number arr[i] was not picked earlier, and arr[i] + subsetSum[mask]
                // is not greater than the targetSum then add arr[i] to the subset
                // sum at subsetSum[mask] and store the result at subsetSum[mask | (1 << i)].
                if (!(mask & (1 << i)) && subsetSum[mask] + arr[i] <= targetSum) {
                    subsetSum[mask | (1 << i)] = (subsetSum[mask] + arr[i]) % targetSum;
                }

            }

            if(subsetSum[(1 << n) - 1] == 0) {
                return true;
            }
        }

        return subsetSum[(1 << n) - 1] == 0;
    }
};