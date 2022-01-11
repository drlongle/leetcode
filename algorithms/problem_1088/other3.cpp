class Solution {
    vector<int> nums = {0,1,8,6,9};
public:

    bool isInvalidNum(long num){

        string s = to_string(num);
        int i = 0; int j = s.length()-1;
        while(j>=i){
            if((s[i]=='1' && s[j]=='1') || (s[i]=='8' && s[j]=='8')
               || (s[i]=='0' && s[j]=='0') || (s[i]=='6' && s[j]=='9') || (s[i]=='9' && s[j]=='6')){
                i++; j--;
            }
            else return false;
        }
        return true;
    }

    void dfs(int n, long num, int& count){

        if(num > n) return;

        if(!isInvalidNum(num)){
            count++;
        }

        num = 10*num;
        for(int i=0;i<nums.size();i++){
            dfs(n,num+nums[i],count);
        }
    }

    int confusingNumberII(int n) {

        int count = 0;
        for(int i=1;i<nums.size();i++){
            dfs(n,nums[i],count);
        }
        return count;
    }
};
