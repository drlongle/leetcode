class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;

        function<void(int,vector<int>)> backtrack = [&](int num,vector<int> v1){
            int start = (v1.size()==0 ? 2 : v1[v1.size()-1]);
            for(int i = start; i <= sqrt(num); i++){
                if(num%i == 0){
                    v1.push_back(i);
                    v1.push_back(num/i);
                    res.push_back(v1);
                    v1.pop_back();
                    backtrack(num/i,v1);
                    v1.pop_back();
                }
            }
        };

        vector<int> v;
        if(n==0){
            return res;
        }
        backtrack(n,v);
        return res;
    }
};
