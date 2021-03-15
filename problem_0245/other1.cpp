class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int w1=-1,w2=-1;
        int minD=INT_MAX;
        int flipflop=word1==word2; //Will tell if we need to alternate the index tracking
        for(int i=0;i<words.size();++i) {
            if((!flipflop&&words[i]==word1)||(flipflop==1&&words[i]==word1)) {
                w1=i;
                flipflop=flipflop?2:0; //If flipflop is 1, make it to 2 so that next index is tracked by w2.
            } else if((!flipflop&&words[i]==word2)||(flipflop==2&&words[i]==word2)) {
                w2=i;
                flipflop=flipflop?1:0; //If flipflop is 2, make it to 1 so that next index is tracked by w1.
            }
            if(w1>=0 && w2>=0) {
                minD=min(minD,abs(w1-w2));
            }
        }
        return minD;
    }
};
