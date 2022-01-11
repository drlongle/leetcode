class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> res, vec;
        istringstream ss(text);
        do{
            string word;
            ss>>word;
            if(word!=""){
                vec.push_back(word);
            }
            
        }while(ss);
        
        int i=0;
        while(i<vec.size()-2) {
            if(vec[i]==first && vec[i+1]==second)
                res.push_back(vec[i+2]);
            i++;
        }
       
        return res;
    }
};
