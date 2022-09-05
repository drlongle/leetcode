class Solution {
  public:
    double col_time(vector<int> &a, vector<int> &b) {
        int gap = b[0] - a[0];
        double speed = a[1] - b[1];

        return gap / speed;
    }

    vector<double> getCollisionTimes(vector<vector<int>> &cars) {
        int n = cars.size();

        vector<double> ans(n, -1);

        stack<int> stk;

        for (int i = n - 1; i >= 0; i--) {
            // if stack top element(speed) is bigger then current speed pop it
            // or if time to collide with stk.top() is greater then time for
            // stk.top() to collide with some next car then also we should pop
            // this car since it is not avaiable to collide as its collide first
            // we next car before collide with current car.
            while (!stk.empty() &&
                   (cars[stk.top()][1] >= cars[i][1] ||
                    (ans[stk.top()] != -1 &&
                     col_time(cars[i], cars[stk.top()]) > ans[stk.top()])))
                stk.pop();

            if (stk.empty())
                ans[i] = -1;
            else
                ans[i] = col_time(cars[i], cars[stk.top()]);

            stk.push(i);
        }

        return ans;
    }
};
