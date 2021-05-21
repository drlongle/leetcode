class Solution {
public:

    void generateAbb(const string &word, string &temp, vector<string> &result){
        if(word.empty()){
            if(temp.empty() == false){
                result.push_back(temp);
            }
            return;
        }

        if(temp.empty() || !isdigit(temp.back())){
            temp.push_back('1');
            generateAbb(word.substr(1),temp,result);
            temp.pop_back();
        } else {

            string prevTemp = temp;
            string num;

            while(temp.empty() == false && isdigit(temp.back())){
                num.push_back(temp.back());
                temp.pop_back();
            }

            reverse(begin(num),end(num));
            int val = stoi(num);
            temp += to_string(val + 1);
            generateAbb(word.substr(1),temp,result);
            temp = prevTemp;
        }

        temp.push_back(word[0]);
        generateAbb(word.substr(1),temp,result);
        temp.pop_back();
    }

    vector<string> generateAbbreviations(string word) {
        string temp;
        vector<string> result;
        generateAbb(word,temp,result);
        return result;
    }
};
