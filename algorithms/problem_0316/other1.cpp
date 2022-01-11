/*

Things to remember while adding or removing a character in the final string (fi)
Add the character if it is not present in the string till now.
Remove if:
- Their are more occurrence of the same character ahead (Check using map)
- Next character in string s (s[i]) is smaller than the last character in final string.
- s[i] is not present in the final string already.
 */

class Solution {
public:
    string removeDuplicateLetters(string s) {
        string fi;
        unordered_map<char, int> m;

        for(int i=0;i<s.length();i++)
            m[s[i]]++;

        for(int i=0;i<s.length();i++){

            while(fi.length()>0 && fi.back()>s[i] && m[fi.back()]>0 && fi.find(s[i])==-1)
                fi.pop_back();

            if(fi.find(s[i])==-1)
                fi.push_back(s[i]);

            m[s[i]]--;
        }
        return fi;
    }
};