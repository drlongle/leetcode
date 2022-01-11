class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> db;
        db[0] = -1;
        int sumVal = 0;
        int size = -1;

        for (int i=0; i<nums.size(); i++){
            sumVal += nums[i];
            if (db.find(sumVal - k) != db.end()){
                size = max(size, i - db[sumVal-k]);
            }

            if (db.find(sumVal) == db.end()){
                db[sumVal] = i;
            }

        }
        return max(0, size);
    }
};
