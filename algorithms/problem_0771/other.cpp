class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int counts=0;
        string::size_type position=0;
        while((position=S.find_first_of(J,position))!=string::npos) {
            position++;
            counts++;
        }
        return counts;
    }
};
