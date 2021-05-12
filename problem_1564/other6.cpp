class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& bs, vector<int>& ws) {
        sort(bs.begin(),bs.end(),[](int a, int b) {
            return a > b;
        });
        for(int i = 1;i<ws.size();i++) {
            ws[i] = min(ws[i-1],ws[i]);
        }
        int ret = 0;
        int i = ws.size() - 1;
        int j = bs.size() - 1;
        while(i>=0&&j>=0) {
            if(ws[i] >= bs[j]){
                j--;
                ret++;
            }
            i--;
        }
        return ret;
    }
};
