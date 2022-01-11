class Solution {
public:

    bool flag= false;
    void func(vector<int>& arr,int idx,long long int p,long long int q,long long int r,long long int s,long long int sum){

        if(idx ==arr.size()){
            if(p==q and q==r and r==s and s==p)
            {
                flag = true;
            }
            return;
        }

        if((p > (sum/4)) or (q>(sum/4)) or (r>(sum/4)) or (s>(sum/4)))
            return;

        if(flag) return;

        func(arr,idx+1,p+arr[idx],q,r,s,sum) ;
        func(arr,idx+1,p,q+arr[idx],r,s,sum) ;
        func(arr,idx+1,p,q,r+arr[idx],s,sum) ;
        func(arr,idx+1,p,q,r,s+arr[idx],sum) ;
    }

    bool makesquare(vector<int>& matchsticks) {

        flag= false;
        long long int sum=0;
        for(int i:matchsticks)
            sum+=i;

        if (matchsticks.size() < 4 || sum % 4) return false;

        sort(matchsticks.rbegin(), matchsticks.rend());

        if(matchsticks[0]> (sum/4))
            return false;

        func(matchsticks,0,0,0,0,0,sum);
        return flag;
    }
};

