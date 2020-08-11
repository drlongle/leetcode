class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(begin(citations), end(citations), [] (int a, int b) {return a > b;});
        int res = 0, sum = 0, sz = citations.size();
        for (int i = 0; i < sz; ++i) {
            if (i+1 <= citations[i])
                res = i+1;
        }
        
        return res;
    }
};
