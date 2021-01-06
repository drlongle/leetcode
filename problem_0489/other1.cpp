class Solution {
public:
    pair<int,int> DIR[4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    unordered_map<int, unordered_map<int, int>> seen;
    int x = 0, y = 0, cdir = 0;
    void cleanRoom(Robot& robot) {
        seen[x][y] = 1;
        robot.clean();
        for (int i=0; i<4; i++) {
            for (;cdir != i; cdir = (cdir + 1) % 4, robot.turnLeft());
            auto d = DIR[i];
            if (!seen[x + d.first][y + d.second] && robot.move()) {
                x += d.first, y += d.second;
                cleanRoom(robot);
                for (;cdir != (i + 2) % 4; cdir = (cdir + 1) % 4, robot.turnLeft());
                robot.move();
                x -= d.first, y -= d.second;
            }
        }
    }
};
