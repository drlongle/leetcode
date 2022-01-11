/*
Since we update the whoel range with the value, its enough if we store the history of the updates with the boundary points along with the value. Now we can iterate backwards from the snapshots, and return the first match (within bounary of updated region). This will contain the latest value for {r,c}. If nothing matches, then we can return from the base rectange.
 */

class SubrectangleQueries {
public:
    vector<vector<int>> snapshots;
    vector<vector<int>> base;
    
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        base = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        vector<int> snap = {row1, col1, row2, col2, newValue};
        snapshots.push_back(snap);
    }
    
    int getValue(int row, int col) {
        int n = snapshots.size();
        for (int i = n - 1; i >= 0; i --) {
            if (row >= snapshots[i][0] && row <= snapshots[i][2] 
                && col >= snapshots[i][1] && col <= snapshots[i][3]) return snapshots[i][4];
        }
        return base[row][col];
    }
};
