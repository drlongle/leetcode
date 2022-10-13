class FindSumPairs {
  public:
    unordered_map<int, int> mp2;

    unordered_map<int, int> mp1;

    vector<int> arr;

    FindSumPairs(vector<int> &nums1, vector<int> &nums2) {

        // store the frequency of nums1 into mp1

        for (auto x : nums1) {
            mp1[x]++;
        }

        arr = nums2;

        // store the frequency of nums2 into mp2

        for (auto x : nums2) {
            mp2[x]++;
        }
    }

    void add(int index, int val) {

        // decrement the count of original val

        mp2[arr[index]]--;

        // if count becomes 0, then remove the old val from mp2

        if (mp2[arr[index]] == 0) {
            mp2.erase(arr[index]);
        }

        // update the val

        arr[index] += val;

        // increment the count of new val

        mp2[arr[index]]++;
    }

    int count(int tot) {

        int count = 0;

        // traverse over mp1, because mp1 will have less size than mp2

        // if we will traverse over the mp2 then it will give TLE

        for (auto x : mp1) {
            int val = x.first;

            int freq = x.second;

            int need = tot - val;

            // update count

            if (mp2.count(need)) {
                count += mp2[need] * freq;
            }
        }

        return count;
    }
};
