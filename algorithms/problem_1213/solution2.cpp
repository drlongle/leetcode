class Solution {
  public:
    vector<int> arraysIntersection(vector<int> &arr1, vector<int> &arr2,
                                   vector<int> &arr3) {
        vector<int> res;
        for (int i = 0, j = 0, k = 0, s1 = arr1.size(), s2 = arr2.size(),
                 s3 = arr3.size();
             i < s1 && j < s2 && k < s3;) {
            if (arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
                res.push_back(arr1[i]);
                ++i, ++j, ++k;
            } else {
                int m = min({arr1[i], arr2[j], arr3[k]});
                if (arr1[i] == m)
                    ++i;
                if (arr2[j] == m)
                    ++j;
                if (arr3[k] == m)
                    ++k;
            }
        }
        return res;
    }
};
