class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int> freq(26, 0);
        for(auto c : s) freq[c-'a']++;
            
        int odds = 0; //keep track of any remaining unique letters
        int evens = 0; //keep track of all the letters that have even count
      
        for(int i = 0; i < freq.size(); i++){
            if(freq[i]){
                evens += freq[i]/2;
                freq[i]%=2;
                if(freq[i] == 1) odds++;
            }
        }
      
        if(odds > k) return 0; //number of unique letters cannot be more than k slots
        
        k -= odds+evens; //expand evens over the remaining slots
        if(k > evens) return 0; //if we have more slots that are unfilled we cannot fill them , therefore return 0
  
        return 1;
    }
};
