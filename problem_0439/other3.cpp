class Solution {
public:
    string parseTernary(string expression) {
        int start = 0;
        return string{go(expression, start)};
    }

    char go(string expr, int &start) {
        if(isdigit(expr[start])) {
            return expr[start];
        }
        char op = expr[start];
        if(op == 'F' || op == 'T') {
            int next = start + 1;
            if(next == expr.size() || expr[next] == ':') return op;
        }
        start += 2;
        char t = go(expr, start);
        start += 2;
        char f = go(expr, start);
        return op == 'T' ? t : f;
    }
};
