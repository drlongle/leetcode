class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> next_greater_number;
        next_greater_number.resize(nums.size());
        stack<int> greater_number_indices;
        int counter = 0;
        
        while ( counter < 2 ){
            for ( int i=nums.size()-1; i>-1; i-- ){
                while ( !greater_number_indices.empty() && 
                        nums[i] >= greater_number_indices.top() )
                    greater_number_indices.pop();
                if ( greater_number_indices.empty() )
                    next_greater_number[i] = -1;
                else 
                    next_greater_number[i] = greater_number_indices.top();
                greater_number_indices.push(nums[i]);
            }
            counter++;
        }
        return next_greater_number;
    }
};
