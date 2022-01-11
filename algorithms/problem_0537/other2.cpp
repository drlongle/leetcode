class Solution {
public:
    complex<int> parse(string num) {
        int i = num.find('+');
        int real = stoi(num.substr(0, i));
        int imaginary = stoi(num.substr(i+1, num.size()-i-2));
        complex<int> res(real, imaginary);
        return res;
    }

    string complexNumberMultiply(string num1, string num2) {
        complex<int> a = parse(num1), b = parse(num2);
        complex<int> res = a * b;

        return to_string(real(res)) + "+" + to_string(imag(res)) + "i";
    }
};
