class Solution {
public:
    bool isNumber(string s) {
        bool signSeen = false, eSeen = false, dotSeen = false, digitSeen = false;
        for (char c: s) {
            switch (c) {
                // signs
                case '-':
                case '+':
                    if (signSeen || digitSeen || dotSeen) return false;
                    signSeen = true;
                    break;
                // dots
                case '.':
                    if (dotSeen || eSeen) return false;
                    dotSeen = true;
                    break;
                // exponentiation
                case 'e':
                case 'E':
                    if (!digitSeen || eSeen) return false;
                    digitSeen = false;
                    signSeen = false;
                    eSeen = true;
                    break;
                // all the rest
                default:
                    if (c < '0' || c > '9') return false;
                    digitSeen = true;
            }
        }
        return digitSeen;
    }
};
