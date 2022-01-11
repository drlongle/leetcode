class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        int currend=INT_MIN;
        int isClipFound=false;
        for(int i=0;i<clips.size();i++){
            if(clips[i][0]==0){
                isClipFound=true;
                currend=max(currend,clips[i][1]);
            }
        }
        if(!isClipFound)
            return -1;
        int s=1;
        int end=currend;
        while(end<T){
            int isClipFound=false;
            for(int i=0;i<clips.size();i++){
                if(clips[i][0]<=end && currend<clips[i][1]){
                    isClipFound=true;
                    currend=clips[i][1];
                }
            }
            if(!isClipFound){
                return -1;
            }
            s++;
            end=currend;
        }
        return s;       
    }
};
