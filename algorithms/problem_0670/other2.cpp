class Solution {
public:
    int maximumSwap(int num) {
        string n=to_string(num);

        // this array contains the maximum element (value and position) following
        // the i-th position
        vector<pair<int,int>> a((int)n.size());

        // max value that we have seen so far and its position
        pair<int,int> p={INT_MIN,-1};

        for(int i=n.size()-1; i>=0; i--) {
            if(p.first<n[i]) {
                p.first=n[i];
                p.second=i;
            }
            a[i]=p;
        }
        for(int i=0; i<n.size(); i++) {
            if(n[i]<a[i].first) {
                swap(n[i],n[a[i].second]);
                break;
            }
        }
        int ans=stoi(n,0,10);
        return ans;
    }
};
