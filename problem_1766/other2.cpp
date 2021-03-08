#define F first
#define S  second
class Solution {
public:
    // Vector for number of 1 to 50
    vector<int>possibleNum;
    // adjecency matrix
    vector<vector<int>>v;
    // nums array declared globally
    vector<int>nums;
    // Final Array to be returned
    vector<int>res;
    vector<int> getCoprimes(vector<int>& _nums, vector<vector<int>>& edges) {
        // Filling the array with values 1 to 50
        for(int i=1; i<=50; i++){
            possibleNum.push_back(i);
        }
        int n = _nums.size();
        nums = _nums;
        res.resize(n , -1);
        v.resize( n ) ;
        // Filling the adjacency Matrix
        for(auto e: edges){
            v[e[0]].push_back( e[1] );
            v[e[1]].push_back( e[0] );
        }
        // the height of all ancestors of root is INT_MIN and index of those are -1
        vector<pair<int,int>>temp(50, {INT_MIN , -1});
        find(0, temp, 1, -1);
        return res;
    }

    void find(int node, vector<pair< int, int >>count, int h, int par ){
        // max Depth Element means minimum closest element
        int maxR = INT_MIN;
        // Index of Closest CoPrime
        int idx ;
        // Iterating over all ancestors
        for(int i=0 ; i<50 ; i++){
            // If the ancestor and node is coprime then we just have to check for maximum depth
            if(__gcd(possibleNum[i],nums[node]) == 1){
                if( maxR<count[i].F ){
                    maxR = count[i].F;
                    idx = count[i].S;
                }
            }
        }
        // If maximum depth is INT_MIN means we have not found any ancestor,
        // else we fill the coPrime ancestor's index
        if(maxR != INT_MIN){
            res[node] = idx;
        }
        // Put current node depth and index in Ancestor Array
        count[nums[node]-1] = {h, node };
        // Interate over all adjacent node and also do not visit parent node again
        for( auto e:v[node] ){
            if(e == par ) continue;
            find( e , count , h+1, node);
        }
        return;
    }
};
