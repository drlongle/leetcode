/*
787. Cheapest Flights Within K Stops
Medium

There are n cities connected by m flights. Each fight starts from city u and arrives at v with a price w.

Now given all the cities and flights, together with starting city src and the destination dst, your task is to find the cheapest price from src to dst with up to k stops. If there is no such route, output -1.

Example 1:
Input:
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 1
Output: 200
Explanation: 
The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as marked red in the picture.

Example 2:
Input: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 0
Output: 500
Explanation: 
The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as marked blue in the picture.

Note:
The number of nodes n will be in range [1, 100], with nodes labeled from 0 to n - 1.
The size of flights will be in range [0, n * (n - 1) / 2].
The format of each flight will be (src, dst, price).
The price of each flight will be in the range [1, 10000].
k is in the range of [0, n - 1].
There will not be any duplicated flights or self cycles.
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
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
    struct Node {
        Node(): price(-1) {}
        int price;
        unordered_map<int, int> edges;
    };

    struct Move {
        Move(int i, int d, int p): id(i), dist(d), price(p) {}
        int id, dist, price;
    };
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<Node> nodes(n);
        for (auto& flight: flights) {
            nodes[flight[0]].edges[flight[1]] = flight[2];
        }
        queue<Move> q;
        q.emplace(src, 0, 0);
        nodes[src].price = 0;
        while (!q.empty()) {
            auto& m = q.front();
            if (m.dist < K + 1) {
                for (auto& p: nodes[m.id].edges) {
                    int price = m.price + p.second;
                    if (nodes[p.first].price < 0 || price < nodes[p.first].price) {
                        q.emplace(p.first, m.dist + 1, price);
                        nodes[p.first].price = price;
                    }
                }
            }
            q.pop();
        }
        
        return nodes[dst].price;
    }
};

int main() {
    Solution sol;
    int n, src, dst, k;
    vector<vector<int>> flights;

    // Output: 200
    n = 3, flights = {{0,1,100},{1,2,100},{0,2,500}};
    src = 0, dst = 2, k = 1;

    // Output: 500
    n = 3, flights = {{0,1,100},{1,2,100},{0,2,500}};
    src = 0, dst = 2, k = 0;

    // Output: 7
    n = 5;
    flights = {{0,1,5},{1,2,5},{0,3,2},{3,1,2},{1,4,1},{4,2,1}};
    src = 0, dst = 2, k = 2;
    
    cout << "Result: " << sol.findCheapestPrice(n, flights, src, dst, k) << endl;
        
    return 0;
}
