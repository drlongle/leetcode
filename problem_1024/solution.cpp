/*
1024. Video Stitching
Medium

You are given a series of video clips from a sporting event that lasted T seconds.  These video clips can be overlapping with each other and have varied lengths.

Each video clip clips[i] is an interval: it starts at time clips[i][0] and ends at time clips[i][1].  We can cut these clips into segments freely: for example, a clip [0, 7] can be cut into segments [0, 1] + [1, 3] + [3, 7].

Return the minimum number of clips needed so that we can cut the clips into segments that cover the entire sporting event ([0, T]).  If the task is impossible, return -1.

Example 1:
Input: clips = [[0,2],[4,6],[8,10],[1,9],[1,5],[5,9]], T = 10
Output: 3
Explanation: 
We take the clips [0,2], [8,10], [1,9]; a total of 3 clips.
Then, we can reconstruct the sporting event as follows:
We cut [1,9] into segments [1,2] + [2,8] + [8,9].
Now we have segments [0,2] + [2,8] + [8,10] which cover the sporting event [0, 10].

Example 2:
Input: clips = [[0,1],[1,2]], T = 5
Output: -1
Explanation: 
We can't cover [0,5] with only [0,1] and [0,2].

Example 3:
Input: clips = [[0,1],[6,8],[0,2],[5,6],[0,4],[0,3],[6,7],[1,3],[4,7],[1,4],[2,5],[2,6],[3,4],[4,5],[5,7],[6,9]], T = 9
Output: 3
Explanation: 
We can take clips [0,4], [4,7], and [6,9].

Example 4:
Input: clips = [[0,4],[2,8]], T = 5
Output: 2
Explanation: 
Notice you can have extra video after the event ends.

Note:
1 <= clips.length <= 100
0 <= clips[i][0], clips[i][1] <= 100
0 <= T <= 100
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
    bool contains(vector<int>& clip, int T) {
        return clip[0] <= T;
    }
    
    int videoStitching(vector<vector<int>>& clips, int T) {
        auto lambda = [] (auto& c1, auto& c2) {return c1[0] < c2[0] || (c1[0] == c2[0] && c1[1] < c2[1]);};
        sort(begin(clips), end(clips), lambda);
        if (clips[0][0] > 0)
            return -1;
        int index = 0, end = 0, res = 0, sz = clips.size();
        while (end < T)  {
            while (index < sz && !contains(clips[index], end))
                ++index;
            if (index == sz)
                return -1;
            int next = clips[index][1];
            while (index + 1 < sz && contains(clips[index+1], end)) {
                ++index;
                next = max(next, clips[index][1]);
            }
            ++res;
            end = next;
            ++index;
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> clips;
    int T;

    // Output: 3
    //clips = {{0,2},{4,6},{8,10},{1,9},{1,5},{5,9}}, T = 10;

    // Output: -1
    //clips = {{0,1},{1,2}}, T = 5;

    // Output: 3
    //clips = {{0,1},{6,8},{0,2},{5,6},{0,4},{0,3},{6,7},{1,3},{4,7},{1,4},{2,5},{2,6},{3,4},{4,5},{5,7},{6,9}}, T = 9;

    // Output: 2
    //clips = {{0,4},{2,8}}, T = 5;

    // Output: -1
    //clips = {{0,2},{4,8}}, T = 5;

    // Output: -1
    //clips = {{0,5},{6,8}}, T = 7;

    // Output: -1
    clips = {{8,10},{17,39},{18,19},{8,16},{13,35},{33,39},{11,19},{18,35}}, T = 20;
    
    // Output: 2
    //clips = {{24,28},{10,56},{50,78},{38,77},{38,78},{3,69},{33,49},{66,89},{73,83},{6,12},{24,86},{67,82},{18,26},{1,57},{13,30},{8,56},{58,78},{2,84},{35,39},{45,51},{30,32},{19,31},{32,70},{1,15},{16,18},{32,87},{32,87},{39,42},{81,84},{25,61},{26,34},{10,82},{17,34},{56,72},{17,22},{8,83},{5,21},{3,79},{12,73},{0,28},{74,76},{41,79},{4,60},{51,90},{10,41},{47,90},{44,56},{13,16},{43,83},{0,22},{30,40},{8,27},{57,58},{0,26},{16,66},{62,89},{2,74},{17,61},{25,28},{23,54},{42,79},{14,28},{26,77},{34,36},{17,42},{72,81},{12,87},{3,57},{81,88},{65,87},{35,74},{19,77},{10,53},{38,75},{14,90},{10,90},{57,62},{37,74},{24,80},{52,63},{52,55},{64,73},{45,79},{12,19},{26,38},{40,81},{28,48},{33,62},{18,50},{9,40}};
    //T = 72;

    //clips = {{41,82},{3,75},{15,90},{21,75},{49,91},{46,59},{6,88},{13,16},{22,92},{42,52},{29,45},{53,74},{72,91},{62,76},{34,47},{16,29},{80,93},{49,88},{2,9},{63,83},{8,36},{0,11},{38,42},{13,70},{39,48},{53,70},{26,100},{45,77},{12,93},{16,40},{64,66},{56,66},{2,52},{65,73},{36,50},{17,32},{10,84},{92,95},{81,90},{45,87},{7,11},{14,30},{57,85},{49,49},{56,100},{17,65},{76,96},{41,91},{44,93},{9,85},{18,86},{19,52},{7,16},{1,25},{8,68},{35,91},{7,66},{70,75},{23,60},{48,72},{8,9},{69,80},{45,77},{42,96},{47,92},{32,49},{72,81},{3,46},{29,92},{14,57},{39,66},{0,15},{49,77},{37,60},{24,77},{15,74},{36,64},{61,76},{10,96},{9,24},{23,55},{35,72},{11,26},{38,71},{44,89},{42,49},{49,52},{28,93},{12,61},{7,69},{42,82},{4,66},{4,58},{2,51},{1,44},{22,67},{6,53},{37,46},{5,65},{10,33}};
    //T = 80;
    
    cout << "Result: " << sol.videoStitching(clips, T) << endl;

    return 0;
}
