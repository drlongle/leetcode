class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size() - k, idx = 0;              //n - for available position, idx - leftmost minimumal number
        vector<int> rez;

        for(int i = idx;i <= n; i++)                   //find leftmost minimal number
            if(nums[i] < nums[idx]) idx = i;

        int tmp = n - idx;                             //value of maximal corrections
        rez.push_back(nums[idx++]);

        while(tmp && idx < nums.size())                //loop for correcting answer
            if(nums[idx] >= rez.back()) rez.push_back(nums[idx++]);       //if next number is convenient
            else
                while(tmp && nums[idx] < rez.back()) {tmp--;rez.pop_back();}//if not - try to correct answer

        if(rez.size() >= k) {rez.resize(k);return rez;}                 //if we don't use all corrections

        for(;idx < nums.size();idx++) rez.push_back(nums[idx]);         //if we use all corrections
        return rez;
    }
};
