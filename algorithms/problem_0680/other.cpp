class Solution {
public:
    bool validPalindrome(string s) {
        auto left{std::cbegin(s)}, right{--std::cend(s)};
        while (std::distance(left, right) > 0)
            if (*left != *right)
            {
                std::string const a(left, right);
                auto reverseA{a};
                std::string const b(std::next(left), std::next(right));
                auto reverseB{b};
                std::reverse(std::begin(reverseA), std::end(reverseA));
                std::reverse(std::begin(reverseB), std::end(reverseB));
                return a == reverseA || b == reverseB;
            }
            else
            {
                ++left;
                --right;
            }
        return true;
    }
};
