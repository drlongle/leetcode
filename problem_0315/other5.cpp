// Binary Indexed Tree or Fenwick Tree
class Solution {
public:
    int bit[100001];
    int offset=1e4+1;
    int n;

    void update(int index){
        for(;index<=100000;index+=index&(-index))
            bit[index]++;
    }

    int query(int index){
        int count=0;
        for(;index>0;index-=index&(-index))
            count+=bit[index];
        return count;
    }

    vector<int> countSmaller(vector<int>& nums) {
        n=nums.size();
        vector<int> ans(n);

        for(int i=n-1;i>=0;i--){
            ans[i]=query(nums[i]+offset-1);
            update(nums[i]+offset);
        }

        return ans;
    }
};
