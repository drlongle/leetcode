class SnakeGame {
private:
    queue<pair<int, int>> foodq;
    int m;
    int n;
    int score = 0;
    list<pair<int, int>> bodyq;

    void get_next_position (int &x, int &y, string direction) {
        if (direction == "R") {
            y++;
        } else if (direction == "L"){
            y--;
        } else if (direction == "U") {
            x--;
        } else if (direction == "D") {
            x++;
        }
    }

    bool snake_alive (int i, int j, int tailx, int taily) {
        if (i < 0 || j < 0 || i >= m || j >= n) {
            return false;
        }

        for (auto temp : bodyq) {
            int bodyx = temp.first;
            int bodyy = temp.second;

            // Check if the next position is any part of the body except for tail
            // Can use set here instead of list
            if (bodyx == tailx && bodyy == taily) {
                break;
            }

            if (i == bodyx && j == bodyy) {
                return false;
            }
        }

        return true;
    }

public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        m = height;
        n = width;

        for (auto temp : food) {
            foodq.push({temp[0], temp[1]});
        }
        bodyq.push_back({0, 0});
    }

    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
        @return The game's score after the move. Return -1 if game over.
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {

        int x = 0;
        int y = 0; // next position

        // Get the new position
        auto head = bodyq.front();
        auto tail = bodyq.back();
        int i = head.first;
        int j = head.second;
        x = i;
        y = j;
        get_next_position(x, y, direction);

        // Check if snake is still alive
        if (!snake_alive(x, y, tail.first, tail.second)) {
            return -1;
        }

        // Check if the next position is food
        if (!foodq.empty()) {
            auto food = foodq.front();
            if (x == food.first && y == food.second) {
                // increase score, pop foodq, add new position to the body do not remove tail
                score++;
                foodq.pop();
                // We wont be popping the tail so check if the new position is the tail
                if (x == tail.first && y == tail.second) {
                    return -1;
                }
                bodyq.push_front({x, y});
                return score;
            }
        }

        bodyq.push_front({x, y});
        bodyq.pop_back();
        return score;
    }
};
