
class Solution {
public:
    int bitwiseComplement(int N)
    {
        if(N==0)
	    return 1;
        int val = (int)log2(N) +1;
        
        int ans = (long long int)pow(2,val) -1 - N;
        
        return ans;
    }
};

