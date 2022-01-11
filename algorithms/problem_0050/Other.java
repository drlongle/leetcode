//one corner case is when n = Integer_MIN_VALUE = -2^31, which is -2147483648
//whereas MAX_VALUE = 2^31-1, which is 1 less than abs(MIN_VALUE);
//Since when n<0, let's say myPow(2,-2), we will convert it as x=1/x and n=-n, which is myPow(1/2,2);
//when we let n=-n and n=MIN_VALUE, it will cost stackOverFlow, hence we need to manually change MIN_VALUE to MAX_VALUE
//However, MAX_VALUE is an odd number, MIN_VALUE is an even number, when x<0, we also need to change x=-x to get a positive result.
	
public double myPow(double x, int n) {
    if(n==0) return 1;
    if(n==1) return x;
    if(n<0){
        if(n==Integer.MIN_VALUE){ 
            n = Integer.MAX_VALUE;
            if(x<0) x = -x;
        }
        else n = -n;
        x = 1/x;
    }
    
    return n%2==0? myPow(x*x,n/2):x*myPow(x*x,n/2);
}
