using ll = long long;
class Solution {
public:
    bool check(ll n) {
        ll num = n, rev = 0, digit;
        do {
            digit = num % 10;
            rev = (rev * 10) + digit;
            num = num / 10;
        } while (num != 0);

        return rev == n;
    }

    ll nextPalindrome(ll palindrome, ll num) { // if num = 123 this function will return 123321
        while (num > 0) {
            palindrome = palindrome * 10 + (num % 10);
            num /= 10;
        }
        return palindrome;
    }

    vector<ll> generatePalindromes(ll left, ll right) {
        vector<ll> res;
        ll number;
        for (int i = 1; (number = nextPalindrome(i, i / 10)) <= right; i++) {
            if (number >= left && number <= right) // odd palindrome
                res.push_back(number); // has length of odd number ex. 222
            number = nextPalindrome(i, i); // has length of even number ex. 2222
            if (number >= left && number <= right) // even palindrome
                res.push_back(number);
        }
        return res;
    }

    int superpalindromesInRange(string left, string right) {
        ll r = stoull(right), l = stoull(left);
        int cnt = 0;
        for (auto &ul : generatePalindromes(sqrt(l), sqrt(r)))
            if (check(ul * ul))
                cnt++;
        return cnt;
    }
};
