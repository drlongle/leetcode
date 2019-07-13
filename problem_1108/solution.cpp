/*
1108. Defanging an IP Address
Difficulty: Easy

Given a valid (IPv4) IP address, return a defanged version of that IP address.
A defanged IP address replaces every period "." with "[.]".

Example 1:
Input: address = "1.1.1.1"
Output: "1[.]1[.]1[.]1"

Example 2:
Input: address = "255.100.50.0"
Output: "255[.]100[.]50[.]0"
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <condition_variable>
#include <cmath>
#include <functional>
#include <future>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long


class Solution {
public:
    string defangIPaddr(string address) {
        ostringstream oss;
        for (char ch: address) {
            if (ch != '.')
                oss << ch;
            else
                oss << "[.]";
        }
        return oss.str();
    }
};

int main() {
    Solution sol;

    return 0;
}

