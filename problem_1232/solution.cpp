/*
1232. Check If It Is a Straight Line
Easy

You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents
the coordinate of a point. Check if these points make a straight line in the XY plane.

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

    int gcd(int x, int y) {
        if (x == 0 || y == 0)
            return 1;
        if (y > x)
            swap(x, y);
        int mod = x % y;
        if (mod == 0)
            return y;
        return gcd(y, mod);
    }
    
    pair<int, int> get_ratio(int x, int y) {
        int g = gcd(abs(x), abs(y));
        if (x < 0) {
            x = -x;
            y = -y;
        }
        
        return make_pair(x/g, y/g);
    }
    
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int sz = coordinates.size();
        tuple<bool, bool, bool> res{true, true, true};
        const auto slop = get_ratio(coordinates[1][1] - coordinates[0][1],
                                    coordinates[1][0] - coordinates[0][0]);
        for (int i = 1; (std::get<0>(res) || std::get<1>(res) || std::get<2>(res)) && i < sz; ++i) {
            if (coordinates[i][0] != coordinates[0][0])
                std::get<0>(res) = false;
            if (coordinates[i][1] != coordinates[0][1])
                std::get<1>(res) = false;
            if (slop != get_ratio(coordinates[i][1] - coordinates[0][1],
                                  coordinates[i][0] - coordinates[0][0]))
                std::get<2>(res) = false;

        }
        return std::get<0>(res) || std::get<1>(res) || std::get<2>(res);
    }
};

int main() {
    Solution sol;
    vector<vector<int>> coord;

    // Expected: true
    coord = {{-3,-2},{-1,-2},{2,-2},{-2,-2},{0,-2}};

    // Expected: true
    coord = {{0,1},{1,3},{-4,-7},{5,11}};

    //coord = {{-4,-3},{1,0},{3,-1},{0,-1},{-5,2}};

    coord = {{-2,12},{2,-8},{6,-28},{-10,52},{-7,37},{4,-18},{7,-33},{1,-3},{-1,7},{8,-38}};
    
    cout << "Result: " << sol.checkStraightLine(coord) << endl;
    
    return 0;
}
