class Solution {
public:
    vector<int> np;
    vector<vector<int>> Rects;
    Solution(vector<vector<int>>& rects) {
        Rects = rects;
        for(auto rect : rects){
            int l1 = rect[2] - rect[0] + 1;
            int l2 = rect[3] - rect[1] + 1;
            int val = np.size() ? np.back() + (l1*l2) : l1*l2;
            np.push_back(val);
        }
    }

    vector<int> pick() {
        int m = np.back();
        int r = rand() % m;
        auto it = upper_bound(np.begin(), np.end(), r);
        int rect = it - np.begin();  //end of step 1
        //step 2 begins
        vector<int> R = Rects[rect];
        int x = rand() % (R[2]-R[0]+1) + R[0];
        int y = rand() % (R[3]-R[1]+1) + R[1];
        return {x, y};
    }
};
