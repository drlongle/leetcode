/*
726. Number of Atoms
Hard

Given a chemical formula (given as a string), return the count of each atom.

The atomic element always starts with an uppercase character, then zero or more lowercase letters, representing
the name.

One or more digits representing that element's count may follow if the count is greater than 1. If the count
is 1, no digits will follow. For example, H2O and H2O2 are possible, but H1O2 is impossible.

Two formulas concatenated together to produce another formula. For example, H2O2He3Mg4 is also a formula.

A formula placed in parentheses, and a count (optionally added) is also a formula. For example,
(H2O2) and (H2O2)3 are formulas.

Given a formula, return the count of all elements as a string in the following form: the first name
(in sorted order), followed by its count (if that count is more than 1), followed by the second name
(in sorted order), followed by its count (if that count is more than 1), and so on.

Example 1:
Input: formula = "H2O"
Output: "H2O"
Explanation: The count of elements are {'H': 2, 'O': 1}.

Example 2:
Input: formula = "Mg(OH)2"
Output: "H2MgO2"
Explanation: The count of elements are {'H': 2, 'Mg': 1, 'O': 2}.

Example 3:
Input: formula = "K4(ON(SO3)2)2"
Output: "K4N2O14S4"
Explanation: The count of elements are {'K': 4, 'N': 2, 'O': 14, 'S': 4}.

Example 4:
Input: formula = "Be32"
Output: "Be32"

Constraints:
1 <= formula.length <= 1000
formula consists of English letters, digits, '(', and ')'.
formula is always valid.
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct Element  {
    Element(string s, int c): str(s), cnt(c) {}
    string str;
    int cnt;
};

class Solution {
public:
    string countOfAtoms(string formula) {
        stack<Element> S;
        int i = 0, sz = formula.size();

        for (; i < sz; ++i) {
            if (formula[i] == '(')
                S.emplace(string(1, formula[i]), 1);
            else if (formula[i] == ')') {
                unordered_map<string, int> cnt;
                int c = 0;
                while (i+1 < sz && isdigit(formula[i+1]))
                    c = c*10 + formula[++i] - '0';
                if (c == 0)
                    c = 1;
                bool stop;
                do {
                    Element& elem = S.top();
                    stop = (elem.str == "(");
                    if (!stop)
                        cnt[elem.str] += elem.cnt;
                    S.pop();
                } while (!stop);
                for (auto& [sym, v]: cnt)
                    S.emplace(sym, v * c);
            } else {
                string sym(1, formula[i]);
                while (i+1 < sz && islower(formula[i+1]))
                    sym.push_back(formula[++i]);
                int c = 0;
                while (i+1 < sz && isdigit(formula[i+1]))
                    c = c*10 + formula[++i] - '0';
                if (c == 0)
                    c = 1;
                S.emplace(sym, c);
            }
        }

        map<string, int> cnt;
        while (!S.empty()) {
            Element& elem = S.top();
            cnt[elem.str] += elem.cnt;
            S.pop();
        }

        ostringstream oss;
        for (auto& [sym, c]: cnt) {
            oss << sym;
            if (c > 1)
                oss << c;
        }

        return oss.str();
    }
};

int main() {
    Solution sol;
    string formula;

    // Output: "H2O"
    formula = "H2O";
    cout << sol.countOfAtoms(formula) << endl;

    // Output: "H2MgO2"
    formula = "Mg(OH)2";
    cout << sol.countOfAtoms(formula) << endl;

    // Output: "K4N2O14S4"
    formula = "K4(ON(SO3)2)2";
    cout << sol.countOfAtoms(formula) << endl;

    // Output: "Be32"
    formula = "Be32";
    cout << sol.countOfAtoms(formula) << endl;

    return 0;
}
