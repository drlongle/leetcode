/*
The thing is except 11 there is not any prime palindrome with even number of digits. Why? Because if
you know about the divisibility test for 11 each palindrome with even digits will be divisible by 11
(Try it yourself). So, 11 is the only prime palindrome with even digits. So, when ever we encounter N
(number we are testing) with even digits, we move on to the first number with higher digit count (with
odd number of digits). For ex. let's say N = 12, then the else condition will make it N = 101 and so on.
The digit_count method simply calculates the number of digits in a number so we can than choose to move
to the next number if digits are odd or move to the first number with higher digit count.
*/

class Solution {
public:
    bool is_prime(int n)
    {
        if(n<2)
            return 0;
        for(int i=2;i*i<=n;i++)
            if(n%i==0)
                return 0;
        return 1;
    }
    int reverse(int n)
    {
        int ret = 0;
        int tmp = n;
        while(tmp)
        {
            int rem = tmp%10;
            ret = ret*10 + rem;
            tmp /= 10;
        }
        return ret;
    }
    int digit_count(int n)
    {
        int ret = 0;
        while(n)
        {
            n/=10;
            ret++;
        }
        return ret;
    }
    int primePalindrome(int N) {
        while(true)
        {
            if(N>=8 && N<=11)
                return 11;
            if(reverse(N)==N && is_prime(N))
                return N;
            int cnt = digit_count(N);
            if(cnt&1)
                N++;
            else
                N = pow(10,cnt)+1;
        }
        return N;
    }
};
