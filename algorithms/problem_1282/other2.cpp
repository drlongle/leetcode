class Solution {
    typedef vector<int> VectorInt;
    typedef vector<VectorInt> MultiVectorInt;
    typedef unordered_map<int, MultiVectorInt> GroupMap;

private:
    void insertToGroupMap(GroupMap& groupMap, int groupSize, int index)
    {
        if (groupMap[groupSize].empty() || groupMap[groupSize].back().size() == groupSize)
            groupMap[groupSize].push_back(VectorInt());

        groupMap[groupSize].back().push_back(index);
    }

public:
    MultiVectorInt groupThePeople(VectorInt& groupSizes)
    {
        GroupMap groupMap;
        MultiVectorInt result;
        
        for (int i = 0; i < groupSizes.size(); ++i)
            insertToGroupMap(groupMap, groupSizes[i], i);

        for (const auto& record : groupMap)
            // groupSize -> [[...], [...]]
            result.insert(result.end(), record.second.begin(), record.second.end());

        return result;
    }
};
