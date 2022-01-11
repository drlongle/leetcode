/*
762. Prime Number of Set Bits in Binary Representation
Easy

Given two integers L and R, find the count of numbers in the range [L, R] (inclusive) having a prime number of set bits in their binary representation.

(Recall that the number of set bits an integer has is the number of 1s present when written in binary. For example, 21 written in binary is 10101 which has 3 set bits. Also, 1 is not a prime.)

Example 1:
Input: L = 6, R = 10
Output: 4
Explanation:
6 -> 110 (2 set bits, 2 is prime)
7 -> 111 (3 set bits, 3 is prime)
9 -> 1001 (2 set bits , 2 is prime)
10->1010 (2 set bits , 2 is prime)

Example 2:
Input: L = 10, R = 15
Output: 5
Explanation:
10 -> 1010 (2 set bits, 2 is prime)
11 -> 1011 (3 set bits, 3 is prime)
12 -> 1100 (2 set bits, 2 is prime)
13 -> 1101 (3 set bits, 3 is prime)
14 -> 1110 (3 set bits, 3 is prime)
15 -> 1111 (4 set bits, 4 is not prime)

Note:
L, R will be integers L <= R in the range [1, 10^6].
R - L will be at most 10000.
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
    int count_bit(int n) {
        int res = 0;
        while (n) {
            ++res;
            n &= n-1;
        }
        return res;
    }
    int countPrimeSetBits(int L, int R) {
        vector<bool> primes(33, true);
        primes[1] = false;
        for (int i = 2; i <= 32; ++i) {
            if (!primes[i])
                continue;
            for (int j = 2*i; j <= 32; j += i)
                primes[j] = false;
        }
        int res = 0;
        for (int n = L; n <= R; ++n) {
            int bit_count = count_bit(n);
            res += primes[bit_count];
        }
        return res;
    }
};

int main() {
    Solution sol;
    return 0;
}
