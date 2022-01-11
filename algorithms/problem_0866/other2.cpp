class Solution {
private:
    int createPalindrome(int i, bool odd, int m) {
        stringstream ss;
        ss << i;
        string s = ss.str();
        reverse(s.begin(),s.end());
        if(odd)
            ss << m;
        ss << s;
        return stoi(ss.str());
    }

    bool isPrime(int N) {
        if (N == 1)
            return false;
        for (int i=2; i<N; i++) {
            if (N % i == 0)
                return false;
        }
        return true;
    }
public:
    int primePalindrome(int N) {
        if(N <10) {
            for (int i = N; i < 10; i++) {
                if (isPrime(i))
                    return i;
            }
        }

        for(int i=1; i<=N;i++) {
            int p = createPalindrome(i, false, 0);
            if(p >= N && isPrime(p))
                return p;

            for (int j=0; j<=9; j++) {
                int f = createPalindrome(i, true, j);
                if(f >= N && isPrime(f))
                    return f;
            }
        }
        return 0;
    }
};
