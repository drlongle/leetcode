class Solution {
public:
    int chalkReplacer(vector<int>& arr, int k) {
        int n = arr.size();
        vector<long long> chalk(arr.begin(), arr.end());
        /*Form the prefix array*/
        for(int i=1;i<n;i++)
            chalk[i] += chalk[i-1];

        k %= chalk[n-1];
        /*Binary Search*/
        int low = 0, high = n-1;
        long long ans = n+1;
        while(low <= high){
            int mid = low +(high - low)/2;
            if(chalk[mid]>k) {ans = mid; high = mid-1;}
            else             {low = mid+1;}
        }
        return (int)ans;
    }
};