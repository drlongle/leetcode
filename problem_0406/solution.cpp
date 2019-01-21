/*
406. Queue Reconstruction by Height
Difficulty: Medium

Suppose you have a random list of people standing in a queue. Each person is
described by a pair of integers (h, k), where h is the height of the person and
k is the number of people in front of this person who have a height greater
than or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.

Example
Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
*/

#include <algorithm>
#include <bitset>
#include <cassert>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/*
People are only counting (in their k-value) taller or equal-height others
standing in front of them. So a smallest person is completely irrelevant for all
taller ones. And of all smallest people, the one standing most in the back is
even completely irrelevant for everybody else. Nobody is counting that person.
So we can first arrange everybody else, ignoring that one person. And then just
insert that person appropriately. Now note that while this person is irrelevant
for everybody else, everybody else is relevant for this person - this person
counts exactly everybody in front of them. So their count-value tells you
exactly the index they must be standing.

So you can first solve the sub-problem with all but that one person and then
just insert that person appropriately. And you can solve that sub-problem the
same way, first solving the sub-sub-problem with all but the last-smallest
person of the subproblem. And so on. The base case is when you have the
sub-...-sub-problem of zero people. You're then inserting the people in the
reverse order, i.e., that overall last-smallest person in the very end and thus
the first-tallest person in the very beginning. That's what the above solution
does. Sorting the people from the first-tallest to the last-smallest, and
inserting them one by one as appropriate.
*/

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(begin(people), end(people),
            [](const pair<int, int>& a, const pair<int, int>& b) {
                return (a.first > b.first ||
                        (a.first == b.first && a.second < b.second));
        });
        
        vector<pair<int, int>> res;
        for (const auto& p: people) {
                res.insert(res.begin() + p.second, p);
        }
        return res;
    }
};

int main(int argc, char** argv) {
    Solution sol;
    vector<pair<int, int>> people;
    
    people = {{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}};
    
    people = {{8,2},{4,2},{4,5},{2,0},{7,2},{1,4},{9,1},{3,1},{9,0},{1,0}};
    
    // Expected: [[3,0],[6,0],[7,0],[5,2],[3,4],[5,3],[6,2],[2,7],[9,0],[1,9]]
    people = {{9,0},{7,0},{1,9},{3,0},{2,7},{5,3},{6,0},{3,4},{6,2},{5,2}};
    
    people = sol.reconstructQueue(people);
    for (const auto& p: people)
        cout << p.first << ", " << p.second << endl;
    return 0;
}
