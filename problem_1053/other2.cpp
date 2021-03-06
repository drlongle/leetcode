class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        vector<int> res = arr;
        if(arr.size() <= 1) return arr;
        int idx1 = -1, idx2 = -1;
        for(int i = arr.size()-2; i >= 0; i--) {
            if(arr[i] > arr[i+1]) {
                idx1 = i;
                break;
            }
        }
        if(idx1 == -1) return res;
        idx2 = idx1+1;
        for(int i = idx1+1; i < arr.size(); i++) {
            if(arr[idx2] < arr[i] and arr[idx1] > arr[i]) {
                idx2 = i;
            }
        }
        swap(res[idx1], res[idx2]);
        return res;
    }
};
