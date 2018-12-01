/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
Problem 354. Russian Doll Envelopes
Difficulty: Hard

You have a number of envelopes with widths and heights given as a pair of
integers (w, h). One envelope can fit into another if and only if both the
width and height of one envelope is greater than the width and height of
the other envelope.

What is the maximum number of envelopes can you Russian doll? (put one inside other)

Note:
Rotation is not allowed.

Example:

Input: [[5,4],[6,4],[6,7],[2,3]]
Output: 3 
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
*/

#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <algorithm>

using namespace std;

struct Doll {
    Doll(int h, int w): distance(1), height(h), width(w) {}
    bool operator<(const Doll& other) const {
        if (height < other.height && width < other.width)
            return true;
        else
            return false;       
    }
    int distance, height, width;
};

class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        vector<Doll> dolls;
        for (auto& p: envelopes) {
            dolls.emplace_back(p.first, p.second);
        }
        for (int i = 0; i < dolls.size(); ++i)
            for (int j = i+1; j < dolls.size(); ++j)
                if (dolls[j] < dolls[i])
                    swap(dolls[i], dolls[j]);
        int result = 0;
        for (int i = 0; i < dolls.size(); ++ i) {
            for (int j = 0; j < i; ++j) {
                if (dolls[j] < dolls[i] && dolls[j].distance + 1 > dolls[i].distance)
                    dolls[i].distance = dolls[j].distance + 1;
            }
            if (result < dolls[i].distance)
                result = dolls[i].distance;
        }

        return result;
    }
};

/*
 * 
 */
int main(int argc, char** argv) {
    Solution sol;
    vector<pair<int, int>> dolls{{5,4},{6,4},{6,7},{2,3}};
    cout << "Result: " << sol.maxEnvelopes(dolls) << endl;

    return 0;
}

