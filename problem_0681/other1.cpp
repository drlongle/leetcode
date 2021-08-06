class Solution {
public:
    string nextClosestTime(string time) {
        string path = "";
        set<string> st;
        backtrack(st, time, path);
        string res = "";
        auto it = st.find(time);
        if(++it == st.end()) it = st.begin();
        return *it;
    }

    void backtrack(set<string>& st, string& time, string& path){
        //Base case: we have 4 digits in path!
        if(path.size()==4){
            string tmp = path;
            tmp.insert(2, 1, ':');
            //Check if the format of path (i.e. 2412) is valid.
            //The valid condition: the HOUR part must be smaller than 24 -> path[0]<2 or path[0]==2 and path[1]<4.
            //The valid condition: the MINUTE part must be smaller than 60 -> check if path[2] < 6
            if ((path[0] < '2' || (path[0] == '2' && path[1] <'4')) && path[2] < '6') st.insert(tmp);
            return;
        }
        //Each call we try to push one digit in the string "path"
        for(int i = 0; i < 5; ++i){
            //skip for avoiding pushing duplicated  ':' in string "path"
            if(time[i] == ':') continue;
            path.push_back(time[i]);
            //After adding a new digit, we keep try to add new digits until we meet the base case.
            backtrack(st, time, path);
            path.pop_back();
        }
    }
};
