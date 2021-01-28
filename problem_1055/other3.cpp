class Solution {
public:
    int shortestWay(string source, string target) {
        int answer=0;
        int start_pos=0;
        for(int i=0;i<target.length();i++){
            int found=source.find(target[i],start_pos);
            if(found==string::npos){
                if(!start_pos) return -1;
                else{
                    ++answer;
                    start_pos=0;
                    --i;
                }
            }
            else start_pos=found+1;
        }
        if(start_pos) return answer+1;
        return answer;
    }
};
