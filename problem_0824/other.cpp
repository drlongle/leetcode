class Solution {
public:
    string toGoatLatin(string S) {
        string ans = "";
        stringstream s(S);
        string word;
        int count = 1;
        while(s >> word)
        {
            if (word[0] == 'I' || word[0] == 'i'||word[0] == 'A'||word[0] == 'a'||word[0] == 'E'||
                word[0] == 'e'|| word[0] == 'O'||word[0] == 'o'||word[0] == 'U'||word[0] == 'u')
            {
                word += "ma";
                for (int i=0; i<count;i++)
                    word += "a";
                ans+= word;
                ans.push_back(' ');
                count++;
            }
            else
            {
                char cc = word[0];
                word.erase(0, 1);
                word.push_back(cc);
                word += "ma";
                for (int i=0; i<count;i++)
                    word += "a";
                ans+= word;
                ans.push_back(' ');
                count++;
            }
        }
        ans.pop_back();
        return ans;
    }
};
