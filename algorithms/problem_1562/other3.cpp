class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        if(n == m) return n;

        set<pair<int, int>> st;
        st.insert({1, n});
        int step = 0;
        for(int i = n - 1; i >= 0; --i){
            if(st.empty()) break;

            auto it = st.upper_bound({arr[i], INT_MAX});
            --it;
            int l = it->first, r = it->second;
            st.erase(it);

            int len1 = arr[i] - l, len2 = r - arr[i];
            if(len1 == m || len2 == m) return n - step - 1;
            if(len1 >= 1) st.insert({l, arr[i] - 1});
            if(len2 >= 1) st.insert({arr[i] + 1, r});

            step++;
        }
        return -1;
    }
};
