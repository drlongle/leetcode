class Solution {
public:

    int helper(vector<string>& digits,string num){
        int ans = 0;
        int i = 0;

        if(num.length() == 0)
            return 1;

        while(i<digits.size() && stoi(digits[i]) < (num[0]-'0')){
            ans += pow(digits.size(),num.length()-1);    /// Adding numbers that start with lesser most significant digit
            i++;
        }
        if(i<digits.size() && stoi(digits[i]) == (num[0]-'0')){
            ans += helper(digits,num.substr(1));   /// calling recursion to find result of numbers that start with the same most significant digit.
        }

        return ans;
    }

    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        sort(digits.begin(),digits.end());   /// Sorting the digits array

        int ans = 0;
        string num = to_string(n);
        int d = num.size();
        for(int i = 1;i<=d-1;i++){
            ans += pow(digits.size(),i);    /// Adding the number of numbers which have less than d digits
        }

        ans += helper(digits,num);    /// helper function finds count of numbers strictly less than num

        return ans;
    }
};
