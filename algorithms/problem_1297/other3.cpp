static const unsigned long long MOD=(unsigned long long) pow(2,63)-1;               //Large mod least collisions.
class Solution {
public:
    unsigned long long int powMod(unsigned long long x,int y) {           //Modular power
        unsigned long long res=1;
        while (y>0) 
        { 
            if(y&1) 
                res=(res*x)%MOD; 
            y=y>>1;
            x=(x*x)%MOD;   
        } 
        return res; 
    } 
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) 
    {
        unsigned long long hash=0,Pow=powMod(51,minSize-1);
        int start=0,result=0;
        unordered_map<int,int> count;           	//Stores count of letters in the window.
        unordered_map<long long,int> occurence;        //Stores count of occurence of that string.
        for(int i=0;i<s.length();i++)			//Sliding window
        {
            count[s[i]]++;						//Increase the count of letter at i.
            if(i-start+1>minSize)                  //Reduce the size of the window if increased to size.
            {
                hash-=(s[start]-'a')*Pow;
                if(--count[s[start]]==0)			//Remove the letter from map if count 0 to track unique letters.
                    count.erase(s[start]);
                start++;
            }
            hash=(hash*51+s[i]-'a')%MOD;
            if(i-start+1==minSize&&count.size()<=maxLetters)	//When the substring in the window matches the constraints.
                result=max(result,++occurence[hash]);     //Increase the occurence count of the string and get max.
        }
        return result;
    }
};
