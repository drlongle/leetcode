
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int sz = (int)arr.size();
        map<int,int>mp;
        for(int i=0;i<sz;i++) mp[arr[i]]++;
        vector<int>elmt;
        for (auto it = mp.begin(); it != mp.end(); ++it){
            elmt.push_back(it->second);  
        }
        sort(elmt.begin(),elmt.end());
        int n = 0;
        for(int i=0;i<elmt.size();i++) {
            if(elmt[i]>k) break;
            k-=elmt[i];
            n++;
        }
        return mp.size() - n;
    }
};
