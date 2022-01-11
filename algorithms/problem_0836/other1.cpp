class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        //check for invalid test cases
        if(rec2[0] == rec2[2] || rec1[1] == rec1[3] || rec2[1] == rec2[3] || rec1[0] == rec1[2]){return false;}
        //check for don't overlap condition
        if(rec1[2] <= rec2[0] || rec1[1] >= rec2[3] || rec1[0] >= rec2[2] || rec2[1] >= rec1[3]){
            return false;
        }
        //otherwise overlap
        return true;
    }
};
