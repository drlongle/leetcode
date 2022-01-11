class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<long long> st;
        vector<double> v;
        int i = 0;
        int j = 0;

        while(j < nums.size()) {
            st.insert(nums[j]);
            if(st.size() == k) {

                multiset<long long>::iterator it = st.begin();
                advance(it, st.size() / 2);

                if(k%2 == 0) {
                    v.push_back((*it + *(--it))/2.0);
                }else {
                    v.push_back(*it);
                }

                st.erase(st.lower_bound(nums[i]));
                i++;
            }
            j++;
        }
        return v;
    }
};
