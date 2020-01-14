/*
911. Online Election
Medium

In an election, the i-th vote was cast for persons[i] at time times[i].

Now, we would like to implement the following query function: TopVotedCandidate.q(int t) will return the number of the person that was leading the election at time t.  

Votes cast at time t will count towards our query.  In the case of a tie, the most recent vote (among tied candidates) wins. 

Example 1:
Input: ["TopVotedCandidate","q","q","q","q","q","q"], [[[0,1,1,0,0,1,0],[0,5,10,15,20,25,30]],[3],[12],[25],[15],[24],[8]]
Output: [null,0,1,1,0,0,1]
Explanation: 
At time 3, the votes are [0], and 0 is leading.
At time 12, the votes are [0,1,1], and 1 is leading.
At time 25, the votes are [0,1,1,0,0,1], and 1 is leading (as ties go to the most recent vote.)
This continues for 3 more queries at time 15, 24, and 8.

Note:
1 <= persons.length = times.length <= 5000
0 <= persons[i] <= persons.length
times is a strictly increasing array with all elements in [0, 10^9].
TopVotedCandidate.q is called at most 10000 times per test case.
TopVotedCandidate.q(int t) is always called with t >= times[0].
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

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */

// Last timestamp for each candidate's update
unordered_map<int, int> ts;

class TopVotedCandidate {
public:

    struct Compare {
        bool operator() (int id1, int id2) const {
            return ts[id1] > ts[id2];
        }
    };

    // Top candidate at timestamps;
    map<int, int> top;

    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int sz = times.size();
        ts.clear();
        unordered_map<int, int> count;
        map<int, set<int, Compare>> levels;
        
        for (int i = 0; i < sz; ++i) {
            int t = times[i];
            int p = persons[i];
            ts[p] = t;
            int c = count[p]++;
            levels[c].erase(p);
            levels[c+1].emplace(p);
            top[t] = *(levels.rbegin()->second.begin());
        }
    }
    
    int q(int t) {
        auto it = top.upper_bound(t);
        if (it == top.end())
            return top.rbegin()->second;
        if (it->first > t)
            --it;
        return it->second;
    }
};

void test_1() {
    vector<int> persons, times;
    
    persons = {0,1,1,0,0,1,0};
    times = {0,5,10,15,20,25,30};
    TopVotedCandidate voteCounter(persons, times);
    for (auto t: {3,12,25,15,24,8})
        cout << voteCounter.q(t) << endl;
}

void test_21() {
    vector<int> persons, times;

    persons = {0,0,1,1,2};
    times = {0,67,69,74,87};
    TopVotedCandidate voteCounter(persons, times);
    for (auto t: {4,62,100,88,70,73,22,75,29,10})
        cout << voteCounter.q(t) << endl;
}


int main() {
    //test_1();    
    test_21();
    return 0;
}
