class Solution {
public:
    string removeKdigits(string num, int k) {
        
        if (k == num.size()) {
            return "0";
        }
        
        int index = 1;
        int removeCount = 0;
        
        stack<int> S;
        S.push(num[0] - '0');
        
        //Iterate through string
        while(index < num.size() && removeCount < k) {
            while(!S.empty() && num[index] - '0' < S.top()) {
                S.pop();
                removeCount++;
                if (removeCount == k) {
                    break;
                }
            }
            S.push(num[index] - '0');  
            index++;
        }
        
        //remove k - removeCount elements from stack
        while(!S.empty() && removeCount < k) {
            S.pop();
            removeCount++;
        }
        
        //build string
        string output;
        while(!S.empty()) {
            output+=to_string(S.top());
            S.pop();
        }
        reverse(output.begin(),output.end());
        while(index < num.size()) {
            output+= num[index];
            index++;
        }
        
        //find first non-zero index
        int nonZeroIndex = 0;
        while(nonZeroIndex < output.length() && output[nonZeroIndex] == '0') {
            nonZeroIndex++;
        }
        
        output = output.substr(nonZeroIndex);
        
        if (output == "") {
            return "0";
        }
        
        return output;
    }
};
