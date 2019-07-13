/*
Intuition : If we have enough partitions to separate repeating numbers, we are good.
*/

#define MAX_SIZE 100001
bool canDivideIntoSubsequences(vector<int>& nums, int K) {
    vector<int> freq(MAX_SIZE,0);
    int buckets = nums.size()/K; // maximum partitions possible of size k
    for(int i=0;i<nums.size();i++)  // store frequency of elements
        freq[nums[i]]++;
    for(int i=1;i<MAX_SIZE;i++) // check if any elem frequency exceed max parition
    {
        if(freq[i]>buckets)
            return false;
    }
    return true;
}

