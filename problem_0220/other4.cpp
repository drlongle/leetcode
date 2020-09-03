/*
1. Create map < nums[i] , [i]> where 0 < i < nums.size()
2. Now we have ordered numbers from vector nums in our map
3. We sequentially scan the numbers in the map (in the range from i, until the number in the map exceeds the original number + t)
*/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multimap <int,int> mp;
        for(int i=0;i<nums.size();i++) mp.insert(pair< int, int >(nums[i], i));

        multimap <int,int>::iterator it;
        multimap <int,int>::iterator itnext;

        for(it=mp.begin();it!=mp.end();it++){
            itnext = it;
            while(true){
                itnext++;
                if(itnext == mp.end()) break;
                long long a = (*it).first;
                long long b = (*itnext).first;
                if(abs(a-b) <= t)  {if(abs((*it).second - (*itnext).second) <= k) return true;}
                else break;
            }
        }
        return false;
    }
};
