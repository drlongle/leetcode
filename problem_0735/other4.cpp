class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stack;

        for (auto& asteroid : asteroids)
        {
            bool flag = true;

            // Keep destroying former asteroids while newest one is headed towards them
            while (!stack.empty() && asteroid < 0 &&
                   stack.back() > 0 && abs(stack.back()) <= abs(asteroid) && flag)
            {
                flag = abs(stack.back()) != abs(asteroid);
                stack.pop_back();
            }

            // Check if newest asteroid should be pushed unto stack
            if (stack.empty() || stack.back() < 0 ||
                asteroid > 0 || asteroid * stack.back() > 0)
            {
                if (flag) stack.push_back(asteroid);
            }
        }
        return stack;
    }
};
