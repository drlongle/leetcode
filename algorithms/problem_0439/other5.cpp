class Solution {
public:
    string ternary(const string& str, int& i){
        char ch = str[i];
        i+=2;
        string a = expr(str,i);
        i++;
        string b = expr(str,i);
        return ch == 'T' ? a : b;
    }

    string expr(const string& str, int& i){
        if(isdigit(str[i])) {
            char ch = str[i];
            i++;
            return string(1,ch);
        }
        else{
            if(i+1<str.size()&&str[i+1] == '?'){
                return ternary(str,i);
            }
            char ch = str[i];
            i++;
            return string(1,ch);
        }
    }
    string parseTernary(string expression) {
        int i = 0;
        return expr(expression,i);
    }
};
