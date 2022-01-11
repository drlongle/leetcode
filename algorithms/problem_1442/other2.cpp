/*
Given an array arr, return the number of triplets (i, j, k), i < j <= k that satisfy a = arr[i]^arr[i+1]^...^arr[j-1] == arr[j]^arr[j+1]^...^arr[k] = b.

Explanation
It is obvious that every triplet (i, j, k) satisfies arr[i]^arr[i+1]^...^arr[k] == 0, and every pair (i, k) that satisfies arr[i]^arr[i+1]^...^arr[k] == 0 can be splitted into k-i triplets, because when j=i+1, i+2, ..., k, it is easy to find out that a=b

To find out the pairs (i, k) that satisfy arr[i]^arr[i+1]^...^arr[k] == 0, we can use a map to store the xor of prefixes, and when two prefixes are equal, like arr[0]^arr[1]^...^arr[i-1] == arr[0]^arr[1]^...^arr[k], we can conclude that (arr[0]^arr[1]^...^arr[i-1]) ^ (arr[0]^arr[1]^...^arr[k]) = arr[i]^arr[i+1]^...^arr[k].

If we check the prefixes with the same xor-sum every time, then the time complexity is O(n^2), which is acceptable. However, because only the sum of starts of the prefixes and the number of prefixes are important, we can optimize the solution to O(n).
 */

// Not-optimized Solution
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        map<int, vector<int>> xorMap;
        xorMap[0].push_back(-1);
        
        int x = 0;
        int ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            x ^= arr[i];
            for (auto j: xorMap[x]) {
                int start = j + 1, end = i;
                ans += end - start;
            }
            xorMap[x].push_back(i);
        }
        
        return ans;
    }
};

// Optimized Solution
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        map<int, pair<int, int>> xorMap;  // xor -> (cnt, sum of starts)
        xorMap[0] = make_pair(1, 0);
        
        int x = 0;
        int ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            x ^= arr[i];
            if (xorMap.find(x) != xorMap.end()) {
                int cnt = xorMap[x].first, sum = xorMap[x].second;
                ans += i * cnt - sum;
            }
            xorMap[x].first++;
            xorMap[x].second += i + 1;
        }
        
        return ans;
    }
};
