class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n,0);
        string sid, type , duration;
        int id, currTime, prevTime;
        stack<int> stk;

        for(int i=0;i<logs.size();++i){
            stringstream ss(logs[i]);
            getline(ss,sid,':');getline(ss,type,':');getline(ss,duration,':');
            id = stoi(sid);
            currTime = stoi(duration);

            if(type=="start") {
                if(!stk.empty())
                    ans[stk.top()] += (currTime - prevTime);
                stk.push(id);
                prevTime = currTime;
            }
            else if (type=="end") {
                ans[stk.top()] += (currTime+1-prevTime);
                stk.pop();
                prevTime=currTime+1;
            }
        }
        return ans;
    }
};