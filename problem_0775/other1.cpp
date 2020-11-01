class Solution {
#define ll int
public:
    bool isIdealPermutation(vector<int>& a) {
        ll maxi=0;
        for(ll i=2;i<(ll)a.size();i++){
            maxi=max(maxi,a[i-2]);
            if(a[i]<maxi)
                return false;
        }
        return true;
    }
};
