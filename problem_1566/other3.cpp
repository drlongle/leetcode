class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int matchedDigits = 0;
        for(int i = 0; i < arr.size() - m ; i++){
            matchedDigits = arr[i] != arr[i + m] ? 0 : matchedDigits + 1;
            if(matchedDigits == (k-1)*m){
                return true;
            }
        }
        return false;
    }
};
