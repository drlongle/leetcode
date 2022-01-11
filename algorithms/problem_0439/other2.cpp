class Solution {
public:
    string parseTernary(string expression) {
        stack<char> q;

        for (int i = expression.size() - 1; i >= 0; --i) {
            char x = expression[i];

            if (x == '?') {
                if (expression[i - 1] == 'T') {
                    char y = q.top();
                    q.pop();
                    q.pop();
                    q.push(y);
                } else if (expression[i - 1] == 'F') {
                    q.pop();
                    char y = q.top();
                    q.pop();
                    q.push(y);
                }
                --i;
            }
            else if (x == ':')
                continue;
            else
                q.push(x);
        }

        return string(1, q.top());
    }
};
