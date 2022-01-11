class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int k) {
        set<int> onBulbs;
        int n = bulbs.size();
        ++k;
        for(int i=0;i<n;++i) {
            int currBulb = bulbs[i];
            onBulbs.insert(currBulb);
            auto iter = onBulbs.find(currBulb);
            if(iter != onBulbs.begin()) {
                auto prevIter = iter;
                prevIter--;
                if(abs(*prevIter-*iter) == k)
                    return i+1;
            }
            auto nextIter = iter;
            nextIter++;
            if(nextIter != onBulbs.end()) {
                if(abs(*nextIter-*iter) == k)
                    return i+1;
            }
        }
        return -1;
    }
};
