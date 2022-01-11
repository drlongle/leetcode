class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int K) {

        int l = 0, r = 1e9;
        while(l < r){
            int mid = l + (r - l + 1) / 2;
            if(ok(sweetness, K + 1, mid)) l = mid;
            else r = mid - 1;
        }
        return l;
    }

private:
    int ok(const vector<int>& sweetness, int K, int sum){

        int n = 0, cur = 0;
        for(int e: sweetness){
            if(cur < sum) cur += e;
            else n ++, cur = e;
        }
        if(cur >= sum) n ++;
        return n >= K;
    }
};
