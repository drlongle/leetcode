class Solution {
public:

    int arr[131073] = {0};
    int N = 131072;

    void AddToElement(int index, int value){
        while(index < N){
            arr[index] += value;
            index = index | (index + 1);

        }
    }

    int PrefixSum(int index){
        int prefix_sum = 0;
        while( index >= 0){
            prefix_sum += arr[index];
            index = (index & (index + 1)) - 1;
        }
        return prefix_sum;
    }

    int createSortedArray(vector<int>& ins){
        long long ans = 0;

        for(int i = 0 ; i < ins.size() ; i++){
            int l = PrefixSum(ins[i] - 1);
            int r = PrefixSum(N) - PrefixSum(ins[i]);
            ans =  (ans + min(l,r));
            AddToElement(ins[i] , 1);
        }

        return int(ans%1000000007);
    }
};
