class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int size_ = arr.size();
        unordered_map<int, unsigned long long> umap_;
        int total = 0;
        int MOD = 1000000007;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < size_; i++) {
            int curr = arr[i];
            umap_[curr] = 1;
            for (int j = 0; j < i; j++) {
                if (arr[i]%arr[j] == 0) {
                    int a = arr[j];
                    int b = arr[i]/arr[j];
                    if (a > b) {
                        break;
                    }
                    else if (a == b) {
                        umap_[curr] += umap_[a]*umap_[a];
                    }
                    else if (umap_.count(b)) {
                        umap_[curr] += 2*umap_[a]*umap_[b];
                    }
                }
            }
            total = (total + umap_[curr])%MOD;
        }

        return total;
    }
};
