/*

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

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rect1, vector<int>& rect2) {
        if (rect1[0] == rect1[2] || rect1[1] == rect1[3] || rect2[0] == rect2[2] || rect2[1] == rect2[3])
            return false;
        bool x_overlap = (rect1[0] < rect2[0] && rect2[0] < rect1[2]) ||
            (rect2[0] < rect1[0] && rect1[0] < rect2[2]);
        x_overlap |= (rect1[0] < rect2[2] && rect2[2] < rect1[2]) ||
                         (rect2[0] < rect1[2] && rect1[2] < rect2[2]);
        bool y_overlap = (rect1[1] < rect2[1] && rect2[1] < rect1[3]) ||
            (rect2[1] < rect1[1] && rect1[1] < rect2[3]);
        y_overlap |= (rect1[1] < rect2[3] && rect2[3] < rect1[3]) ||
                         (rect2[1] < rect1[3] && rect1[3] < rect2[3]);

        return x_overlap && y_overlap;
    }
};

int main() {
    Solution sol;
    vector<int> rect1, rect2;

    // True
    rect1 = {7,8,13,15};
    rect2 = {10,8,12,20};
    //cout << boolalpha << sol.isRectangleOverlap(rect1, rect2) << endl;

    // False
    rect1 = {-1,0,1,1};
    rect2 = {0,-1,0,1};
    cout << boolalpha << sol.isRectangleOverlap(rect1, rect2) << endl;

    return 0;
}
