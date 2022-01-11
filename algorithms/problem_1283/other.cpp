class Solution {
public:
    unsigned int ceil(float f){
        if (f>(int) f) return f+1;
        return f;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        long long int s=0;
        int i,d;
        int l=1,h=1000000;
        while(l<h){
            s=0;
            d=(l+h)/2;
            for (int &it:nums)
                s+=(it+d-1)/d;
            if(s>threshold) l=d+1;
            else h=d;
        }
        return l;
    }
};
