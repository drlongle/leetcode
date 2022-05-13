
/*
We have to find the room id which is in the minimum distance with the query id and
room size is greater or equal the query size. So we can sort the rooms and queries based
on the size in descending order and then search the queries. From larger to smaller
room size we can insert ids in the Set and then use binary search to find the min distance
id for query id. As we will add ids to Set N time, so complexity NLogN and also for K
queries we do binary search K times with complexity KLogN.
 */

bool comparator(const vector<int>&a,const vector<int>&b)
{
    return a[1] > b[1];
}

class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        
        int qsize = queries.size();
        vector<int>res(qsize);
        
        // add indexes of the queries as extra value
        for(int i=0;i<qsize;i++)
            queries[i].push_back(i);
        
        // sort rooms and queries in descending order of room size
        sort(begin(rooms),end(rooms),comparator);
        sort(begin(queries),end(queries),comparator);
        
        // ascending order of room ids
        set<int>ids;
        
        for(int i=0,j=0;i<qsize;i++)
        {
            // insert all romm ids for rooms with size >= query size
            for(;j<rooms.size() && rooms[j][1]>=queries[i][1];j++)
                ids.insert(rooms[j][0]);
            
            // if ids empty then room size does not exist and so set -1
            if(ids.empty())
            {
                res[queries[i][2]] = -1;
                continue;
            }
            
            int id,find,prevVal,nextVal;
            
            // find the upper bound of the query room id
            find = queries[i][0];
            auto iter = ids.upper_bound(find);
            
            // if iter is in the begin then no previous possible and begin value is the closest
            if(iter==ids.begin()) id = *ids.begin();
            else
            {
                // min distance id will be either in upper bound iter or its previous iter
                
                nextVal = iter==ids.end() ? INT_MAX : *iter;
                prevVal = *prev(iter);
                
                id = abs(prevVal-find)<=abs(nextVal-find) ? prevVal : nextVal;
            }
            
            res[queries[i][2]] = id;
        }
        
        return res;
    }
};
