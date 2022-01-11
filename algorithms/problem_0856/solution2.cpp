#include <string>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    
    int score(stack<int>& st) {
        int res = 0;
        while (st.size() && -1 != st.top()) {
            res += st.top();
            st.pop();                    
        }
        return res;
    }
    
    int scoreOfParentheses(string S) {
        stack<int> st;
        for (char ch: S) {
            if (ch == '(')
                st.push(-1);
            else {
                int res = score(st);
                cout << "res: " << res << endl;
                if (!res)
                    res = 1;
                else
                    res *= 2;
                if (st.top() == -1)
                    st.pop();
                res += score(st);
                cout << "pushing " << res << endl;
                st.push(res);
            }
        }
        
        
        return st.top();
    }
};

int main()
{
    Solution sol;
    string s = "((((((())))()())))";

    cout << sol.scoreOfParentheses(s) << endl;
}
