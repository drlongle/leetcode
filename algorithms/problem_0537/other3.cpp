class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int i = num1.find('+'), j = num2.find('+');
        int r1 = stoi(num1.substr(0, i)), r2 = stoi(num2.substr(0, j));
        int i1 = stoi(num1.substr(i + 1)), i2 = stoi(num2.substr(j + 1));
        complex<int> c = complex(r1, i1) * complex(r2, i2);
        return to_string(c.real()) + "+" + to_string(c.imag()) + "i";
    }
};
