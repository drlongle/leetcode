class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        if(dict.size() == 0)
            return s;
        vector<vector<int>> intervals;
        for(int i=0;i<dict.size();i++){
            string word = dict[i];
            int j = 0;
            while(j<s.length() && s.find(word, j) != string::npos){
                j = s.find(word, j);
                vector<int> interval;
                interval.push_back(j);
                interval.push_back(j+word.length()-1);
                intervals.push_back(interval);
                j++;
            }
        }

        if(intervals.size() == 0)
            return s;
        sort(intervals.begin(), intervals.end(), [](const auto & lhs, const auto & rhs){
            return lhs[0] < rhs[0];
        });

        string ans = "";

        int start = intervals[0][0];
        int end = intervals[0][1];
        ans+=s.substr(0, start);
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0] - end <=1)
                end = max(end, intervals[i][1]);
            else{
                ans+="<b>" + s.substr(start, end-start+1) + "</b>";
                ans+= s.substr(end+1, intervals[i][0]-1-end);//mat[end+1][intervals[i][0] - 1];
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        if(start<=end)
            ans+="<b>" + s.substr(start, end-start+1) + "</b>";
        if(end+1<=s.length()-1)
            ans+= s.substr(end+1, s.length()-1-end); //mat[end+1][s.length()-1];
        return ans;
    }
};
