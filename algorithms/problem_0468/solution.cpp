/*
468. Validate IP Address

Write a function to check whether an input string is a valid IPv4 address or IPv6 address or neither.

IPv4 addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers, each ranging from 0 to 255, separated by dots ("."), e.g.,172.16.254.1;

Besides, leading zeros in the IPv4 is invalid. For example, the address 172.16.254.01 is invalid.

IPv6 addresses are represented as eight groups of four hexadecimal digits, each group representing 16 bits. The groups are separated by colons (":"). For example, the address 2001:0db8:85a3:0000:0000:8a2e:0370:7334 is a valid one. Also, we could omit some leading zeros among four hexadecimal digits and some low-case characters in the address to upper-case ones, so 2001:db8:85a3:0:0:8A2E:0370:7334 is also a valid IPv6 address(Omit leading zeros and using upper cases).

However, we don't replace a consecutive group of zero value with a single empty group using two consecutive colons (::) to pursue simplicity. For example, 2001:0db8:85a3::8A2E:0370:7334 is an invalid IPv6 address.

Besides, extra leading zeros in the IPv6 is also invalid. For example, the address 02001:0db8:85a3:0000:0000:8a2e:0370:7334 is invalid.

Note: You may assume there is no extra space or special characters in the input string.

Example 1:
Input: "172.16.254.1"
Output: "IPv4"
Explanation: This is a valid IPv4 address, return "IPv4".

Example 2:
Input: "2001:0db8:85a3:0:0:8A2E:0370:7334"
Output: "IPv6"
Explanation: This is a valid IPv6 address, return "IPv6".

Example 3:
Input: "256.256.256.256"
Output: "Neither"
Explanation: This is neither a IPv4 address nor a IPv6 address.
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
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> parse(string& str, char token) {
        istringstream iss(str);
        string part;
        vector<string> res;
        while (getline(iss, part, token)) {
            res.push_back(std::move(part));
        }
        return res;
    }

    bool valid_ip4(string& addr) {
        vector<string> parts = parse(addr, '.');
        if (parts.size() != 4)
            return false;
        for (auto& part: parts) {
            int sz = part.size();
            if ((sz > 1 && part[0] == '0') || sz > 3 || sz == 0)
                return false;
            int sum = 0;
            for (char ch: part) {
                if (!isdigit(ch))
                    return false;
                sum = sum*10 + ch - '0';
                if (sum > 255)
                    return false;
            }
        }
        
        return true;
    }

    bool valid_ip6(string& addr) {
        vector<string> parts = parse(addr, ':');
        if (parts.size() != 8)
            return false;
        for (auto& part: parts) {
            int sz = part.size();
            if (sz == 0 || sz > 4)
                return false;
            for (char ch: part) {
                if (!isalnum(ch))
                    return false;
                if (isalpha(ch))
                    ch = tolower(ch);
                if (ch > 'f')
                    return false;
            }
        }
        return true;
    }
    
    string validIPAddress(string& ip) {
        if (ip.find('.') != string::npos) {
            if (valid_ip4(ip) && ip.back() != '.')
                return "IPv4";
        } else if (ip.find(':') != string::npos) {
            if (valid_ip6(ip) && ip.back() != ':')
                return "IPv6";
        }
        return "Neither";
    }
};

int main() {
    Solution sol;
    string ip;

    // Output: "IPv4"
    ip = "172.16.254.1";
    //cout << sol.validIPAddress(ip) << endl;

    // Output: "IPv6"
    ip = "2001:0db8:85a3:0:0:8A2E:0370:7334";
    ////cout << sol.validIPAddress(ip) << endl;
    
    // Output: "Neither"
    ip = "256.256.256.256";
    //cout << sol.validIPAddress(ip) << endl;

    // Output: "Neither"
    ip = "2001:0db8:85a3:0:0:8A2E:0370:7334:";
    //cout << sol.validIPAddress(ip) << endl;

    // Output: "IPv6"
    ip = "2001:0db8:85a3:033:0:8A2E:0370:7334";
    //cout << sol.validIPAddress(ip) << endl;

    // Output: "IPv6"
    ip = "20EE:Fb8:85a3:0:0:8A2E:0370:7334";
    cout << sol.validIPAddress(ip) << endl;
        
    return 0;
}
