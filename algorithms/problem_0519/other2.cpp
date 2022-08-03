class Solution {
public:
    set<pair<int,int>> st;
    int r,c;
    Solution(int m, int n) {
        r=m,c=n;
    }

    vector<int> flip() {
        int row = rand()%r;
        int col = rand()%c;
        while(st.find({row,col})!=st.end()){
            row = rand()%r;
            col = rand()%c;
        }
        st.insert({row,col});
        return {row,col};
    }

    void reset() {
        st.clear();
    }
};
