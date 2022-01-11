// Fenwick Tree

class NumArray {
public:
    vector<int> arr;
    int N;

    void AddToElement(int index, int value){     //add to element with [index] and increase rest
        while(index < N){                          //size of BIT
            arr[index] += value;
            index = index | (index + 1);
        }
    }

    void ModifyElement(int index, int value){    //modify element with [index] and increase rest
        int current = PrefixSum(index) - PrefixSum(index - 1);
        AddToElement(index , value - current);
    }

    int PrefixSum(int x){                        //calculate prefix_sum
        int prefix_sum = 0;
        for (; x >= 0; x = (x & (x + 1)) - 1)
            prefix_sum += arr[x];

        return prefix_sum;
    }

    NumArray(vector<int>& nums){                 //initialization of BIT
        N = nums.size();
        arr.resize(N+1,0);
        for(int i = 0; i < N ; i++) AddToElement(i, nums[i]);
    }

    void update(int index, int val){
        ModifyElement(index, val);
    }

    int sumRange(int left, int right){          //Sum in range [left, right]
        return left ? PrefixSum(right) - PrefixSum(left - 1) : PrefixSum(right);
    }
};
