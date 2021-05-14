class Solution {
public:
    vector <string> putDecimal(string &s, int startIdx, int endIdx){
        //if subpart's len == endIdx-startIdx+1 == 1, return itself
        if(endIdx - startIdx + 1 == 1)
            return {s.substr(startIdx, 1)};
        vector <string> ret;
        // if subpart does not contain a leading zero, we can add the whole subpart to the result without placing a decimal point
        if(s[startIdx] != '0')
            ret.push_back(s.substr(startIdx, endIdx - startIdx + 1));
        //edge case 1 mentioned above
        if(s[endIdx] == '0')
            return ret;
        for(int i = startIdx ; i < endIdx ; i++){
            //edge case 2 mentioned above
            if(s[startIdx] == '0' && i > startIdx)
                break;
            string tmp = s.substr(startIdx, i - startIdx + 1) + '.' + s.substr(i + 1, endIdx - i);
            ret.push_back(tmp);
        }
        return ret;
    }
    vector<string> ambiguousCoordinates(string s) {
        int n = s.size();
        //preprocess the input string
        s = s.substr(1, n-2);
        vector <string> ans;
        n = s.size();
        // trying to put commas at all the valid positions
        for(int i = 0 ; i < n-1 ; i++){
            // divide into left and right subparts
            vector <string> part1 = putDecimal(s, 0, i), part2 = putDecimal(s, i+1, n-1);
            //combine the results of the left and right subparts
            for(string s1:part1){
                for(string s2:part2)
                    ans.push_back('(' + s1 + ", " + s2 + ')');
            }
        }
        return ans;
    }
};
