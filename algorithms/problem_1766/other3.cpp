class Solution {
public:
    int _gcd(int a, int b){
        int temp;
        while(b){
            temp = a%b;
            a = b;
            b = temp;
        }
        return a;
    }
    void find(vector<vector<int>> &data, vector<int>& nums, vector<int>& ans,
              vector<bool> &check, vector<vector<int>> &gcd, int index, vector<int> &val){
        // update answer for all value after this node
        vector<int> next(51, index);
        for(int n : gcd[nums[index]]){
            next[n] = val[n];
        }
        ans[index] = val[nums[index]];
        // prevent repeat
        check[index] = true;
        // next node
        for(int i=0 ; i<data[index].size() ; i++){
            if(check[data[index][i]]== false){
                find(data, nums, ans, check, gcd, data[index][i], next);
            }
        }
    }
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        vector<int> ans(nums.size(), -1);
        vector<int> val(51, -1);
        vector<bool> check(nums.size(), false);
        vector<vector<int>> data(nums.size(), vector<int>());
        vector<vector<int>> gcd(51, vector<int>());

        // pre compute gcd for all value
        for(int i=1 ; i<51 ; i++){
            for(int j=i ; j<51 ; j++){
                if(_gcd(i, j) != 1){
                    gcd[i].push_back(j);
                    gcd[j].push_back(i);
                }
            }
        }
        // build graph
        for(auto &e:edges){
            data[e[0]].push_back(e[1]);
            data[e[1]].push_back(e[0]);
        }
        find(data, nums, ans, check, gcd, 0, val);

        return ans;
    }
};
