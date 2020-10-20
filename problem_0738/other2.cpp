class Solution {
    vector<int> convert_to_arr(int n){
        vector<int> v;
        while(n){
            int t = n%10;
            n = n/10;
            v.push_back(t);
        }
        reverse(v.begin(),v.end());
        return v;
    }

    int convert_int(vector<int> nums){
        int ans = 0;
        for(int i=0;i<nums.size();i++)
            ans = ans*10 + nums[i];
        return ans;
    }
public:
    int monotoneIncreasingDigits(int N) {
        vector<int> nums = convert_to_arr(N);
        stack<int> st;
        int n = nums.size();
        for(int i=n-1;i>=0;i--) {
            if(st.size()>0 and nums[i]>nums[st.top()]) {
                while(st.size()>0){
                    nums[st.top()] = 9;
                    st.pop();
                }
                nums[i] -= 1;
            }
            st.push(i);
        }

        return convert_int(nums);
    }
};
