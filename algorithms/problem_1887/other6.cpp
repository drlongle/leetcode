class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<int, int> table;
        for (auto num: nums){
            table[num]++;
        }
        int sum = 0;
        int i = 0;
        for (auto p: table){
            sum += i * p.second;
            ++i;
        }
        return sum;
    }
};
