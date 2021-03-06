class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        string s(arr.begin(), arr.end());
        for(int i=0;i+k*m<=s.size();i++){
            string t = s.substr(i, m);
            bool isGood = true;
            for(int d=1;d<k;d++){
                if(s.substr(i+m*d,m) != t){
                    isGood = false;
                    break;
                }
            }
            if(isGood) return true;
        }
        return false;
    }
};