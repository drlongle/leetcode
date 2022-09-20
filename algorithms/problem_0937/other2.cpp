class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        
        vector<pair<string,string>> letterLogs;
        vector<string> digiLogs;
        
        for(auto s:logs)
        {
            int i=0;
           while(i<s.size() and s[i]!=' ') //skip the indetifier as identifier kuch b ho skta
                i++;
            
            i++;  //as we are standing at ' ' 
            
            if(isdigit(s[i]))   //if first char after space is digit then all are digit 
                digiLogs.push_back(s);  //pushed into digiLogs
            
            else  //sorting on the basis of content not the identifier so make pair
                letterLogs.push_back({s.substr(i),s.substr(0,i)});  //'a2 abcf' --> {abcf,a2}
        }
        
        sort(letterLogs.begin(),letterLogs.end());
        
        vector<string> ans;
        for(auto i:letterLogs)  //sorted letterLogs now push in ans
            ans.push_back(i.second+i.first); 
        
        for(auto i:digiLogs)  //now push the digiLogs in the same order as it is in orig arr
            ans.push_back(i);
        
        return ans;        
    }

};
