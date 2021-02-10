/*
To solve the problem in O(n * log(n)) is pretty hard. And I believe it must be an overkill in a real interview.
The basic idea is from https://stackoverflow.com/questions/34882666/is-it-possible-to-count-the-number-of-distinct-substrings-in-a-string-in-on
There are some (pretty complex) algorithms to construct suffix tree in O(n) time, you can refer to
Algorithms on Strings, Trees, and Sequences: Computer Science and Computational Biology Chapter 6.
To be honest, I spent a whole afternoon on the book but still didn't get it.
Luckily enough, we can construct suffix array in O(n * log(n)) time and it's not very complex.
This video could help: https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-851-advanced-data-structures-spring-2012/lecture-videos/session-16-strings/

And Competitive programming 3 section 6.6 provides very detailed implementation. My code is directly cited from the book.
*/

const int N = 510;
int RA[N], RA_TMP[N];
int SA[N], SA_TMP[N];
int C[N];
int LCP[N];
int PLCP[N];
int PHI[N];
class Solution {
public:
    void countingSort(int k,int n) {
        memset(C,0,sizeof(C));
        const int maxi = max(300,n);
        for(int i = 0;i<n;i++) {
            C[i+k>=n?0:RA[i+k]]++;
        }
        int sum = 0;
        for(int i = 0;i<maxi;i++) {
            int t = C[i];
            C[i] = sum;
            sum += t;
        }
        for(int i = 0;i<n;i++) {
            SA_TMP[C[SA[i]+k>=n?0:RA[SA[i]+k]]++] = SA[i];
        }
        for(int i = 0;i<n;i++) {
            SA[i] = SA_TMP[i];
        }
    }
    void constructSA(string& s) {
        int n = s.size();
        for(int i = 0;i<n;i++) {
            SA[i] = i;
            RA[i] = s[i];
        }
        for(int k = 1;k<n;k<<=1) {
            countingSort(k,n);
            countingSort(0,n);
            int r = 0;
            RA_TMP[SA[0]] = r;
            for(int i = 1;i<n;i++) {
                RA_TMP[SA[i]] = (RA[SA[i-1]] == RA[SA[i]] && RA[SA[i-1] + k] == RA[SA[i] + k])?r:++r;
            }
            for(int i = 0;i<n;i++) {
                RA[i] = RA_TMP[i];
            }
            if(RA[SA[n-1]] == n-1) {
                break;
            }
        }
    }
    void computeLCP(string& s) {
        int n = s.size();
        int i,L;
        PHI[SA[0]] = -1;
        for(int i = 1;i<n;i++) {
            PHI[SA[i]] = SA[i-1];
        }
        for(i=L=0;i<n;i++) {
            if(PHI[i]== -1) {
                PLCP[i] = 0;
                continue;
            }
            while(s[i+L] == s[PHI[i]+L]) L++;
            PLCP[i] = L;
            L = max(L-1,0);
        }
        for(int i = 0;i<n;i++) {
            LCP[i] = PLCP[SA[i]];
        }
    }
    int countDistinct(string s) {
        s.push_back('$');
        constructSA(s);
        computeLCP(s);
        int n = s.size();
        int sum = accumulate(LCP,LCP+n,0);
        int total = n*(n-1)/2;
        return total - sum;
    }
};
