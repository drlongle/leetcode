class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& maxGroupSizes) {
        // groups (group size, group)
        unordered_map <int, vector<int>> groups; 
        vector<vector<int>> ans;
        
        for(int id = 0; id < maxGroupSizes.size(); id++)
        {
            auto &currGroup = groups[maxGroupSizes[id]]; 
            // insert id into proper group
            currGroup.push_back(id);
            
            // insert group into answer, clear "full" group
            if(currGroup.size() == maxGroupSizes[id])
            {
                ans.push_back(currGroup);
                currGroup.clear();
            } 
        } 
        return ans;
    }
};
