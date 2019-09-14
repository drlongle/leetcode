/*
1184. Distance Between Bus Stops
Easy

A bus has n stops numbered from 0 to n - 1 that form a circle. We know the distance between all pairs of neighboring stops where distance[i] is the distance between the stops number i and (i + 1) % n.

The bus goes along both directions i.e. clockwise and counterclockwise.

Return the shortest distance between the given start and destination stops.

Example 1:
Input: distance = [1,2,3,4], start = 0, destination = 1
Output: 1
Explanation: Distance between 0 and 1 is 1 or 9, minimum is 1.

Example 2:
Input: distance = [1,2,3,4], start = 0, destination = 2
Output: 3
Explanation: Distance between 0 and 2 is 3 or 7, minimum is 3.

Example 3:
Input: distance = [1,2,3,4], start = 0, destination = 3
Output: 4
Explanation: Distance between 0 and 3 is 6 or 4, minimum is 4.
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
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int n = distance.size();
        vector<int> prefix(n);

        if (start > destination)
            swap(start, destination);

        int dist = 0;
        for (int i = start; i < destination; ++i)
            dist += distance[i];
        int sum = accumulate(begin(distance), end(distance), 0);
        
        return min(dist, sum - dist);
    }
};

int main() {
    Solution sol;
    vector<int> distance;
    int start, destination;
    
    distance = {1,2,3,4}, start = 0, destination = 1;

    distance = {1,2,3,4}, start = 0, destination = 2;

    distance = {1,2,3,4}, start = 0, destination = 3;
    
    cout << "Result: " << sol.distanceBetweenBusStops(distance, start, destination) << endl;
    
    return 0;
}
