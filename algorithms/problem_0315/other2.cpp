void merge(vector<int> &nums, int low, int mid, int high, vector<int> &indexMap,
           vector<int> &res) {
    vector<int> helper;

    int il = low;
    int ir = mid + 1;
    int inverseCount = 0;

    while (il <= mid && ir <= high) {
        if (nums[indexMap[il]] <= nums[indexMap[ir]]) {
            helper.push_back(indexMap[il]);
            res[indexMap[il]] += inverseCount;
            il++;
        } else {
            helper.push_back(indexMap[ir]);
            ir++;
            inverseCount++;
        }
    }

    while (il <= mid) {
        helper.push_back(indexMap[il]);
        res[indexMap[il]] += inverseCount;
        il++;
    }

    while (ir <= high) {
        helper.push_back(indexMap[ir]);
        ir++;
    }

    move(helper.begin(), helper.end(), indexMap.begin() + low);
}

void mergeSort(vector<int> &nums, int low, int high, vector<int> &indexMap,
               vector<int> &res) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(nums, low, mid, indexMap, res);
        mergeSort(nums, mid + 1, high, indexMap, res);
        merge(nums, low, mid, high, indexMap, res);
    }
}

class Solution {
public:
    vector<int> countSmaller(vector<int> &nums) {
        vector<int> indexMap(nums.size(), 0);
        vector<int> res(nums.size(), 0);

        iota(indexMap.begin(), indexMap.end(), 0);
        mergeSort(nums, 0, nums.size() - 1, indexMap, res);

        return res;
    }
};
