unordered_map<int,int> count;
bool canDivideIntoSubsequences(vector<int>& nums, int K) {
    for(int num:nums) {
        count[num]++;
    }
    int groups=nums.size()/K;
    for(auto c:count) {
        if(c.second/groups>1)  return false;
        if(c.second/groups==1 && c.second%groups>0)   return false;
    }
    return true;
}

