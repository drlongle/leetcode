class Solution {
  public:
    void duplicateZeros(vector<int> &arr) {

        for (int rindex = 0, sz = arr.size(), windex = 0; windex < sz;
             ++rindex, ++windex) {
            int val = arr[rindex] % 10;
            if (val == 0) {
                windex++;
            } else
                arr[windex] += val * 10;
        }
        for (int i = 0, sz = arr.size(); i < sz; ++i)
            arr[i] /= 10;
    }
};
