#include<bits/stdc++.h>
#define ll long long

#define pb push_back
#define ff first
#define endl "\n"
#define ss second
#define setbits(x)          __builtin_popcountll(x)
#define lp(x,a,n) for(ll x=a; x<n; x++)
#define lpi(x,a,n) for(int x=a; x<n; x++)
#define w(t) int t; cin>>t; while(t--)
#define vi vector<int>
#define vll vector<ll>
#define pll pair<ll, ll>
#define pii pair<int, int>
#define inf 1e9
#define LB lower_bound
#define UB upper_bound
const ll mod = 1000000007;
using namespace std;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        // calculate prefix sum
        int n = matrix.size();
        int m = matrix[0].size();
        int dp[n+1][m+1];
        lp(i,0,n+1){
            lp(j,0,m+1){
                if(i == 0|| j == 0){
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-1] + matrix[i-1][j-1]-dp[i-1][j-1];
                }
            }
        }
        int sum,count = 0;
        lp(i,1,n+1){
            lp(j,1,m+1){
                // all sub-matrices passing through i,j are:
                lp(i1,i,n+1){
                    lp(j1,j,m+1){
                        sum = dp[i-1][j-1]+dp[i1][j1] - (dp[i-1][j1]+dp[i1][j-1]);
                        if(sum == target){
                            count++;
                        }
                    }
                }
            }
        }

        return count;
    }
};
