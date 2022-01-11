/*
401. Binary Watch

Difficulty:Easy
Total Accepted:51.1K
Total Submissions:114.2K

A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).

Each LED represents a zero or one, with the least significant bit on the right.

For example, the above binary watch reads "3:25".

Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.

Example:

Input: n = 1
Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
Note:
The order of output does not matter.
The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".

*/

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

class Solution {
public:
    void getTime(vector<bool>& digits, vector<string>& res) {
        int hour = 0, minute = 0;
        for (size_t i = 0; i < 4; ++i)
            hour = (hour << 1) + digits[i];
        for (size_t i = 4; i < 10; ++i)
            minute = (minute << 1) + digits[i];
        if (hour >= 12 || minute >= 60)
            return;

        ostringstream oss;
        oss << hour << ":";
        if (minute < 10)
            oss << 0;
        oss << minute;

        res.push_back(oss.str());
    }

    void backtrack(vector<bool>& digits, vector<string>& res,int index,
        int sum, int num) {
        if (num == sum) {
            getTime(digits, res);
            return;
        }
        for (int i = index; i < 10; ++i) {
            digits[i] = true;
            backtrack(digits, res, i + 1, sum + 1, num);
            digits[i] = false;
        }
    }

    vector<string> readBinaryWatch(int num) {
        vector<bool> digits(10, false);
        vector<string> res;

        backtrack(digits, res, 0, 0, num);

        return res;
    }
};

int main(int argc, const char* argv[])
{
    Solution sol;
    vector<string> res;
    int n;

    n = 1;
    n = 2;
    n = 4;

    res = sol.readBinaryWatch(n);
    reverse(begin(res), end(res));

    vector<string> expected = {"0:15","0:23","0:27","0:29","0:30","0:39","0:43","0:45","0:46","0:51","0:53","0:54","0:57","0:58","1:07","1:11","1:13","1:14","1:19","1:21","1:22","1:25","1:26","1:28","1:35","1:37","1:38","1:41","1:42","1:44","1:49","1:50","1:52","1:56","2:07","2:11","2:13","2:14","2:19","2:21","2:22","2:25","2:26","2:28","2:35","2:37","2:38","2:41","2:42","2:44","2:49","2:50","2:52","2:56","3:03","3:05","3:06","3:09","3:10","3:12","3:17","3:18","3:20","3:24","3:33","3:34","3:36","3:40","3:48","4:07","4:11","4:13","4:14","4:19","4:21","4:22","4:25","4:26","4:28","4:35","4:37","4:38","4:41","4:42","4:44","4:49","4:50","4:52","4:56","5:03","5:05","5:06","5:09","5:10","5:12","5:17","5:18","5:20","5:24","5:33","5:34","5:36","5:40","5:48","6:03","6:05","6:06","6:09","6:10","6:12","6:17","6:18","6:20","6:24","6:33","6:34","6:36","6:40","6:48","7:01","7:02","7:04","7:08","7:16","7:32","8:07","8:11","8:13","8:14","8:19","8:21","8:22","8:25","8:26","8:28","8:35","8:37","8:38","8:41","8:42","8:44","8:49","8:50","8:52","8:56","9:03","9:05","9:06","9:09","9:10","9:12","9:17","9:18","9:20","9:24","9:33","9:34","9:36","9:40","9:48","10:03","10:05","10:06","10:09","10:10","10:12","10:17","10:18","10:20","10:24","10:33","10:34","10:36","10:40","10:48","11:01","11:02","11:04","11:08","11:16","11:32"};

    cout << "res len: " << res.size() << ", expected: " << expected.size() << endl;
    for (size_t i = 0; i < min(res.size(), expected.size()); ++i)
        if (res[i] != expected[i]) {
            cout << "i: " << i << ", res: " << res[i] << ", expected: " << expected[i] << endl;
            break;
        }
    //for (auto& st: res)
    //    cout << st << endl;

    return 0;
}

