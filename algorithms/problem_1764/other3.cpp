class Solution {
public:
    bool solve(vector<vector<int>>&groups,vector<int>&nums,int lps[]){
        int n=groups.size();
        int idx=0;
        int i=0;
        int j=0;
        while(i<nums.size()){
            if(groups[idx][j]==nums[i]){
                i++;
                j++;
            }

            if(j==groups[idx].size()){
                idx++;
                j=0;
            } else if(groups[idx][j]!=nums[i]){
                if (j!=0){
                    j=lps[j-1];
                } else{
                    i++;
                }
            }

            if (idx==n){
                return true;
            }
        }

        return false;
    }

    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int n=nums.size();
        int lps[n];
        lps[0]=0;
        int j=0;
        int i=1;
        while(i<n){
            if (nums[i]==nums[j]){
                j++;
                lps[i]=j;
                i++;
            } else {
                if(j!=0){
                    j=lps[j-1];
                }else{
                    lps[i]=0;
                    i++;
                }
            }
        }

        return solve(groups,nums,lps);
    }
};

