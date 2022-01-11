#include <queue>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minBuildTime(vector<int>& blocks, int split) {

        priority_queue<int, vector<int>, greater<int>> pq;
        for(int e: blocks) pq.push(e);
        while(pq.size() >= 2){
            int a = pq.top();pq.pop();
            int b = pq.top(); pq.pop();
            pq.push(b + split);
        }
        return pq.top();
    }
};

int main() {
    Solution sol;
    vector<int> blocks;
    int split;

    // Output: 1
    blocks = {1}, split = 1;

    // Output: 7
    blocks = {1,2}, split = 5;

    // Output: 4
    blocks = {1,2,3}, split = 1;

    cout << "Result: " << sol.minBuildTime(blocks, split) << endl;
}
