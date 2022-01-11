class Solution {
public:
    const int MOD = 1e9 + 7;
    int countVowelPermutation(int n) {
        vector<int> arr(5 ,1);

        for(int i = 1; i < n; i++){
            int arr1 = arr[1];
            int arr2 = arr[2];
            arr[1] = (arr[0] + arr2)%MOD;
            arr[2] = (arr1 + arr[3])%MOD;
            arr[0] = ((arr1 + arr2)%MOD + arr[4])%MOD;
            arr[4] = (arr2 + arr[3])%MOD;
            arr[3] = arr2%MOD;
        }
        int sum = 0;
        for(int i = 0;i < 5; i++){
            sum += arr[i];
            sum %= MOD;
        }
        return sum;
    }
};
