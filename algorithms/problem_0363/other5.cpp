class Solution {
public:
    int ksubarray(vector<int> &v, int k){
        int sum = 0, maxi = INT_MIN;
        set<int> csum;
        csum.insert(0);

        for(int i=0; i<v.size(); i++){
            sum+=v[i];

            auto lb = csum.lower_bound(sum - k);

            if(lb != csum.end())
                maxi = max(maxi, sum - *lb);

            csum.insert(sum);
        }

        return maxi;
    }

    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> vec(m,0);
        int ans = INT_MIN;
        for(int i = 0; i<n; i++){
            vec.assign(vec.size(), 0);
            for(int j = i; j<n; j++){
                for(int ele = 0; ele<m; ele++){
                    vec[ele] += (matrix[ele][j]);
                }
                int ksum = ksubarray(vec,k);
                if(ksum>ans && ksum<=k) ans = ksum;
            }

        }
        return ans;
    }

};