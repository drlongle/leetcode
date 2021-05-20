/*
The regex uses a modified ECMAScript format https://en.cppreference.com/w/cpp/regex/ecmascript
and works as follows, from left to right:

[+-]? matches the optional + or - sign of our number.

(\d+(\.\d*)?|\.\d+) matches the integer or decimal number:
a. \d+(\.\d*)? matches an integer or a decimal number with optional decimal digits, e.g: 1, 1.0 or 1. (same as 1.0).
b. \.\d+ matches a decimal number with an omitted integer component, e.g: .3 (same as 0.3).

([eE][+-]?\d+)? matches the optional integer exponent of 10 at the end of the number, e.g: e3, e+3, e-3:
a. [eE][+-]? matches an upper or lowercase e followed by the optional + or - sign.
b. \d+ matches the digits of the integer exponent.

Some notes:

static is used so the std::regex is instantiated and compiled once only.
If we don't do this, most of our runtime will be spent recompiling the same regex over and over again!

The R"_()_" syntax denotes a raw string literal (using _ as the delimiter), which allows us to avoid
the need for escaping '\' in the regex string.
*/

class Solution {
public:
    bool isNumber(string s) const {
        static regex r(R"_([+-]?(\d+(\.\d*)?|\.\d+)([eE][+-]?\d+)?)_");
        return regex_match(s, r);
    }
};
