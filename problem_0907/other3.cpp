class Solution {
    int mod = 1e9+7;
public:
    int sumSubarrayMins(vector<int>& A) {
        A.push_back(0);
        int n = A.size();
        long long ans = 0 ;
        int vz = 0, cnt[n];  //vz is size of stack

        for(int i = 0 ; i < n ; i++)
        {
            //stack is empty (or) top of stk < A[i] then just add A[i] to stk and continue
            if(vz==0 || A[vz-1]<A[i])
            {
                A[vz] = A[i] ; cnt[vz] = 1; vz++;
                continue ;
            }

            //now here stack is not empty and A[vz-1] >= A[i]

            while(vz>0 && A[vz-1] >= A[i])
            {
                if(A[vz-1]==A[i])
                {
                    cnt[vz-1] = (1 + cnt[vz-1]) % mod ;
                    break;
                }

                //A[vz-1]>A[i]
                // for A[vz-1] i.e.top has 2 options 1.add to A[vz-2] or 2. Add to A[i]

                if(vz>=2 && A[vz-2]>=A[i]) //add to vz-2
                {
                    ans = (ans + (((A[vz-1] - A[vz-2]) % mod) * sigma(cnt[vz-1]))%mod ) % mod ;
                    cnt[vz-2] = (cnt[vz-2] + cnt[vz-1]) % mod ;
                    vz--;
                }
                else    //add vz-1 to i
                {
                    ans = (ans + (((A[vz-1] - A[i])%mod) * sigma(cnt[vz-1]))%mod ) % mod ;
                    A[vz-1] = A[i] ;
                    cnt[vz-1] = (1 + cnt[vz-1]) % mod ;
                    break;
                }
            }
        }
        
        return ans%mod;
    }

    long long sigma(int k)
    {
        k = k % mod ;
        if(k%2)
        {
            return (k * ((k+1)>>1))%mod ;
        }
        return (long long)((k+1) * (k>>1)) % mod ;
    }
};
