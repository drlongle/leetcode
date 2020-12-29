class Solution {
public:
    bool isStrobogrammatic(string num) {
        char S[] = {'2', '3', '4', '5', '7'};

        for (int i = 0; i < 5; i++)
            if (num.find(S[i]) != string::npos) // can find S[i] in num
                return false;

        string reverse_num = "";
        for (int i = num.length() - 1; i >= 0; i--)
            reverse_num += num[i];

        for (int i = 0; i < reverse_num.length(); i++)
            if (reverse_num[i] == '6')    reverse_num[i] = '9';
            else if (reverse_num[i] == '9')    reverse_num[i] = '6';

        return reverse_num == num;
    }
};
