class Solution {
public:
    // mirrors the left half side digits to right half side: 123->121, 1234->1221
    long mirror(long n)
    {
        auto x = to_string(n);
        for(int i=0,j=x.size()-1;i<x.size(),j>=0;i++,j--)
            x[j] = x[i];
        return stol(x);
    }
    // return the value of mid digit: 123 -> 010, 1234-> 0010
    long mid_value(string x)
    {
        int m = x.size()%2?(x.size()-1)/2:x.size()/2;
        for(int i=0;i<x.size();i++)
            x[i] = i==m?'1':'0';
        return stol(x);
    }
    // return absolute difference of x and y if not equal and LONG_MAX if equal
    long diff(long x, long y)
    {
        long dif = abs(x-y);
        if(dif==0)
            return LONG_MAX;
        else
            return dif;
    }
    string nearestPalindromic(string n) {
        long R, N = stol(n), M = mid_value(n),global_diff = LONG_MAX;
        // we get the result by modifying the mid digit and then mirroring it
        for(int i=-9;i<=9;i++)
        {
            if(i<0 && (N<-i*M))
                continue;
            auto X = mirror(N+i*M);
            auto dif = diff(X,N);
            if(dif<global_diff || (dif==global_diff && X<R))
            {
                global_diff = dif;
                R = X;
            }
        }
        return to_string(R);
    }
};
