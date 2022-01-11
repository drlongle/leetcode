string shortestPalindrome(string s)
    {
        int n = s.size();
        if(n == 0) return s;
        
        int i = n;
        string v = s; 
        reverse(v.begin(), v.end());  //Reverse s.
        
        for(; i >= 1; --i)
        {
            if(s.substr(0, i) == v.substr(n - i)) break;    //palindrome?
        }
        for(; i < s.size(); i += 2) s = s[i] + s;   //Construct
        return s;
    }

