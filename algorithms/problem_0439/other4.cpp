class Solution {
public:
    string parseTernary(string const & expression) {
        // Call recursive parse function starting at the first index.
        // A character is returned, so just convert to a string for the final result.
        int next = 0;
        char result = parseTernary(expression, 0, next);
        return string{result};
    }

    // Recursively parse expression s starting at index begin.
    // The next character to parse is saved in index next.
    // The result of parsing the expression is returned.
    char parseTernary(string const & s, int begin, int & next) {
        // Stop recursing if have no further sub-expression to parse,
        // so the character at index begin itself is the result.
        char c = s[begin];
        next = begin + 1;
        if (isdigit(c) or next == s.size() or s[next] != '?')
        {
            return c;
        }

        // Parse sub-expression "A" from "T?A:B" where we start at (begin + 2) to skip "T?".
        char t = parseTernary(s, begin + 2, next);

        // Parse sub-expression "B" from "T?A:B" where we start at (next + 1) to skip "A:".
        char f = parseTernary(s, next + 1, next);

        // Return either char t or f depending on c.
        return (c == 'T') ? t : f;
    }
};
