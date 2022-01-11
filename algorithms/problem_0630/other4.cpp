class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        sort(courses.begin(), courses.end(), [](auto &x, auto &y) {
            return x[1] < y[1];
        });

        multiset<int> taken;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += courses[i][0];
            taken.insert(courses[i][0]);

            while (sum > courses[i][1]) {
                sum -= *taken.rbegin();
                taken.erase(prev(taken.end()));
            }
        }

        return taken.size();
    }
};
