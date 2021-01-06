class Solution {
public:
    enum class Direction {
        UP = 0,
        LEFT = 1,
        DOWN = 2,
        RIGHT = 3
    };

    void cleanRoom(Robot& robot) {
        int row = 0, col = 0;
        cleanRoom(robot, 0, 0, Direction::UP);
    }

    void cleanRoom(Robot& robot, int row, int col, Direction cur_dir) {
        visited[row][col] = true;
        robot.clean();

        Direction dest_dir = cur_dir;
        for (int i = 0; i < 4; i++) {
            int dest_row, dest_col;
            std::tie(dest_row, dest_col) = transformRobotDir(dest_dir, row, col);

            if (!visited[dest_row][dest_col] && robot.move()) {
                cleanRoom(robot, dest_row, dest_col, dest_dir);
                // This is THE MAJOR difference beteen normal DFS problems and this problem - in typical
                // DFS problems we automatically unroll to the previous call. But the Robot is a stateful class
                // not under our control. Hence we need to drag it back into the previous cell.
                rollBackRobot(robot);

                // Why turn right? We switch directions by turning left everytime but since the robot
                // has returned to it's original cell in the reverse direction, we turn right instead of left.
                robot.turnRight();
            } else {
                // Turn 90 deg and explore the other direction.
                robot.turnLeft();
            }
            dest_dir = static_cast<Direction>((static_cast<int>(dest_dir) + 1) % 4);
        }

        // This is a classical DFS pitfall. We set visited to false in "true" backtracking problems in order
        // to find "other" feasible solutions. But in in this case, there are no "alternate" solutions to be found.
        // My Home Vacuum Cleaner mostly has this BUG :). If uncommented, the robot keeps cleaning the
        // same rooms/area again and again.
        //visited[row][col] = false;
    }
private:
    std::pair<int, int> transformRobotDir(Direction dest_dir, int row, int col) {
        switch(dest_dir) {
            case Direction::UP:
                row--;
                break;
            case Direction::LEFT:
                col--;
                break;
            case Direction::DOWN:
                row++;
                break;
            case Direction::RIGHT:
                col++;
                break;
        }
        return {row, col};
    }
    void rollBackRobot(Robot& robot) {
        robot.turnLeft();
        robot.turnLeft();
        robot.move();
    }
    std::unordered_map<int, std::unordered_map<int, bool>> visited;
};
