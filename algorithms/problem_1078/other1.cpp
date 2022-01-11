class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        
        vector<string> thirds;
        istringstream iss(text);
        bool firsted = false;
        bool seconded = false;
        
        string word;
        while(iss >> word) {
            if (firsted && seconded){
                thirds.push_back(word);
                firsted = false;
                seconded = false;
            }
            
            if (word == first){
                firsted = true;
                if (seconded == true){
                    seconded = false;
                }
            } else if (word == second){
                if (firsted == true){
                    seconded = true;
                }
            } else {
                if (firsted){
                    firsted = false;
                }
                if (seconded){
                    seconded = false;
                }
            }
        }
        return thirds;
    }
};
