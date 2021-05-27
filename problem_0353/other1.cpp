class SnakeGame {
private:
    queue<pair<int, int>> qu;
    unordered_set<int> snake_cells;
    vector<vector<int>> food;
    int height, width, curr_idx;
public:
    SnakeGame(int width, int height, vector<vector<int>>& food) : width(width), height(height), food(food), curr_idx(0) {
        qu.push({0, 0});
        snake_cells.insert(0);
    }

    int move(string direction) {
        auto head = qu.back();
        if (direction == "U") {
            head.first--;
        } else if (direction == "D") {
            head.first++;
        } else if (direction == "L") {
            head.second--;
        } else {
            head.second++;
        }
        if (!(head.first >= 0 && head.first < height && head.second >= 0 && head.second < width)) {
            return -1;
        }
        if (curr_idx < food.size() && head == make_pair(food[curr_idx][0], food[curr_idx][1])) {
            curr_idx++;
        } else {
            auto front = qu.front();
            qu.pop();
            snake_cells.erase(front.first * 10000 + front.second);
        }
        if (snake_cells.count(head.first * 10000 + head.second)) {
            return -1;
        }
        qu.push(head);
        snake_cells.insert(head.first * 10000 + head.second);
        return snake_cells.size() - 1;
    }
};
