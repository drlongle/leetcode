class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        deque<int>dq;

        for(int i=nums.size()-1;i>=0;i--){
            while(dq.size()>0 && dq.front() > i+k)
                dq.pop_front();
            if(dq.size()<=0)
                dq.push_back(i);
            else{
                nums[i] = nums[dq.front()] + nums[i];
                while(dq.size()>0 && nums[dq.back()] <=nums[i])
                    dq.pop_back();
                dq.push_back(i);
            }
        }

        return nums[0];
    }
};
