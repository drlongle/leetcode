/*
The preprocessing for KMP actually computes the longest prefix that is a suffix, so we can just use the same algorithm.

Obligatory Roy video: https://www.youtube.com/watch?v=GTJr8OvyEVQ
*/

class Solution {
public:
    vector<int> lps(string& word)
    {
        vector<int> lp(word.length(), 0);
        
        int index = 0;
        for(int i = 1; i < word.length();)
        {
            if(word[i] == word[index])
            {
                index++;
                lp[i] = index;
                i++;
            }
            else
            {
                if(index != 0)
                    index = lp[index-1];
                else
                    i++;
            }
        }
        
        return lp;
    }
    
    string longestPrefix(string s) {
        vector<int> lp = lps(s);
        
        return s.substr(0, lp.back());
    }
};
