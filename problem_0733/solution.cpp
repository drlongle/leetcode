/*
733. Flood Fill
Easy

An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.
Example 1:
Input: 
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: 
From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
by a path of the same color as the starting pixel are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected
to the starting pixel.
Note:

The length of image and image[0] will be in the range [1, 50].
The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
The value of each color in image[i][j] and newColor will be an integer in [0, 65535].
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
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int>> offsets{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int m = image.size();
        int n = image[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.emplace(sr, sc);
        int color = image[sr][sc];
        while (!q.empty()) {
            auto& p = q.front();
            int i = p.first;
            int j = p.second;
            image[i][j] = newColor;
            for (auto& offset: offsets) {
                int ni = i + offset[0];
                int nj = j + offset[1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && image[ni][nj] == color && !visited[ni][nj]) {
                    visited[ni][nj] = true;
                    q.emplace(ni, nj);
                }
            }
            q.pop();
        }

        return image;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> image;
    int sr, sc, newColor;

    // Output: [[2,2,2],[2,2,0],[2,0,1]]
    sr = 1, sc = 1, newColor = 2;
    image = {{1,1,1},{1,1,0},{1,0,1}};

    image = sol.floodFill(image, sr, sc, newColor);
    for (auto& row: image) {
        copy(begin(row), end(row), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }
    
    return 0;
}
