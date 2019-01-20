
// reservoir sampling

class Solution {
public:
    vector<int> storage;
    Solution(vector<int> nums) {
        storage.insert(storage.end(),nums.begin(),nums.end());
    }

    int pick(int target) {
        int count=0;
        int ans;
        for(int i=0;i<storage.size();i++){
            if(storage[i]==target){ // number encountered.
                count++;
                if(rand()%count<1) ans=i;
            }
        }
        return ans;
    }
};
