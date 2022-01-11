class Solution {
public:
    int pathSum(vector<int>& nums) {
        unordered_map<int, int> sumMap; // node id -> cumulative sum until the node
        unordered_set<int> leafSet;  // collect leaf nodes
        // we can traverse from the vector as it is sorted in ascending order
        for (auto i=0; i<nums.size(); i++) {
            int level = nums[i]/100; // compute level of current node
            int pos = (nums[i]-level*100) / 10; // compute position in the level of current node
            int curID = level*10 + pos; // level+pos is an ID of each node
            int curVal = nums[i] % 10;  // current value
            int parentID = (level-1)*10 + (pos+1)/2;  // compute the id of parent node (imagine tree structure)
            if (sumMap.count(parentID)) {
                // if there is a parent sum, we add the parent's sum to the cumulative sum of the current node
                sumMap[curID] = curVal + sumMap[parentID];
            } else {
                // if there is no parent, cumaltive sum is just current value (e.g., root)
                sumMap[curID] = curVal;
            }
            // update leaf node information (we should remove parent since the current node is the leaf we have seen so far
            if (leafSet.count(parentID)) leafSet.erase(parentID);
            leafSet.insert(curID);
        }
        int total = 0;
        // we only add all leaf nodes' cumulative sum
        for (int id: leafSet) total += sumMap[id];
        return total;
    }
};
