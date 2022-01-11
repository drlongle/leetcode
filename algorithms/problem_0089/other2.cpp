class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans = {0};
        for(int i=0; i<n; i++) {
            vector<int> tmp;
            for(int j=0; j<ans.size(); j++)  tmp.push_back(ans[j]);
            for(int j=ans.size()-1; j>=0; j--) tmp.push_back(ans[j] + (1<<i));
            swap(ans, tmp);
        }
        return ans;
    }
};

