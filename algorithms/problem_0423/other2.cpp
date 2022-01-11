string originalDigits(string s) {
        string digitStrs[10] = {"zero", "one", "two", "three", "four", "five",
                               "six", "seven", "eight", "nine"};
        unordered_map<char, int> cmap;
        for(char c : s)
            cmap[c]++;
        
        int counts[10] = {};
        counts[0] = cmap['z'];
        counts[2] = cmap['w'];
        counts[4] = cmap['u'];
        counts[6] = cmap['x'];
        counts[8] = cmap['g'];
        for(int i = 0; i <= 8; i += 2)
            for(char c : digitStrs[i])
                cmap[c] -= counts[i];       
        
        counts[1] = cmap['o'];
        counts[3] = cmap['t'];
        counts[5] = cmap['f'];
        counts[7] = cmap['s'];
        for(int i = 1; i <= 7; i += 2)
            for(char c : digitStrs[i])
                cmap[c] -= counts[i];  
        
        counts[9] = cmap['i'];
        
        string res;
        for(int i = 0; i <= 9; i++)
            res += string(counts[i], '0' + i);
        
        return res;
    }


