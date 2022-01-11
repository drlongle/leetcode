class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for(int i = 0; i < asteroids.size(); i++)
        {
            if(s.empty() || asteroids[i] * s.top() > 0 || s.top() < 0 && asteroids[i] > 0)
                s.push(asteroids[i]);
            else{

                // top of stack astroid explodes
                if(abs(s.top()) < abs(asteroids[i])){
                    s.pop();
                    i--;
                }

                // both collide and die
                else if(abs(s.top()) == abs(asteroids[i]))
                    s.pop();

            }
        }
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;

    }
};
