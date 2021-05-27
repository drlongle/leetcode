class SnakeGame {
public:
    queue<vector<int>> q;
    set<vector<int>> s;
    int row;
    int col;
    vector<int> pos;
    int score;
    queue<vector<int>> meat;
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        for(auto x : food){
            meat.push(x);
        }
        q.push({0,0});
        row = height;
        col = width;
        s.insert({0,0});
        pos = {0,0};
        score = 0;
    }

/** Moves the snake.
    @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
    @return The game's score after the move. Return -1 if game over.
    Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        if(direction == "U"){
            pos[0] -= 1;
        }else if(direction == "L"){
            pos[1] -= 1;
        }else if(direction == "R"){
            pos[1] += 1;
        }else{
            pos[0] += 1;
        }
        if(pos[0] < 0 || pos[0] >= row || pos[1] < 0 || pos[1] >= col || (s.count(pos) != 0 && q.front() != pos)){
            return -1;
        }

        if(meat.front() == pos){
            meat.pop();
            score++;
            q.push(pos);;
            s.insert(pos);
        }else{
            vector<int> temp = q.front();
            s.erase(temp);
            q.pop();
            q.push(pos);
            s.insert(pos);
        }
        return score;
    }
};
