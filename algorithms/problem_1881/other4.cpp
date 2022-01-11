class Solution {
public:
    string maxValue(string num, int x) {
        int n = num.length();
        bool is_neg = (num[0] == '-');
        int i= 0;
        char ch = x + '0';
        if (is_neg) i++;
        for (; i < n; i++) {
            if (is_neg && num[i] > ch)  break;
            if (!is_neg && num[i] < ch) break;
        }
        if (i == n) num.push_back(ch);
        else num.insert(i, 1, ch);
        return num;
    }
};
