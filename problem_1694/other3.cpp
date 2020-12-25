class Solution {
public:
    string reformatNumber(string number) {
        return regex_replace(regex_replace(number, regex("\\D"), ""), regex("...?(?=..)"), "$0-");
    }
};
