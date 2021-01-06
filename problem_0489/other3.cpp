class Solution {
public:
    void cleanRoom(Robot& robot) {
        unordered_map<int, unordered_map<int,bool>> visited;
        Clean(robot, 0, 0, 0, visited);
    }

    void Clean(Robot &robot, int x, int y, int d, unordered_map<int,unordered_map<int,bool>> &visited) {
        static const int dirs[] = {-1, 0, 1, 0, -1};
        visited[x][y] = true;
        robot.clean();

        for (int i = 0; i < 4; ++i) {
            const int m = x + dirs[d];
            const int n = y + dirs[d+1];
            if (!visited[m][n] && robot.move()) {
                Clean(robot, m, n, d, visited);
            }
            TurnRight(robot, d);
        }
        TurnRight(robot, d);
        TurnRight(robot, d);
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }

    void TurnRight(Robot &robot, int &d) {
        d = (d + 3) % 4;
        robot.turnRight();
    }
};
