class Solution {
public:
    vector<int> row_offset = {0,  0, 1, -1}; //right, left, down, up
    vector<int> col_offset = {1, -1, 0,  0};

    void Dijkstra(vector<vector<int>>& maze, vector<int>& start, vector<vector<int>>& distance){

        // HEAP definition
        auto comparator = [](const pair<vector<int>, int>& a, const pair<vector<int>, int>& b){
            return a.second > b.second;
        };
        priority_queue< pair<vector<int>, int>, vector<pair<vector<int>, int>>, function<bool(const pair<vector<int>, int>& a, const pair<vector<int>, int>& b)>> min_heap(comparator);

        min_heap.push(make_pair(start, 0));
        while(!min_heap.empty()){
            pair<vector<int>, int> S = min_heap.top();
            min_heap.pop();
            //if(distance[S.first[0]][S.first[1]] < S.second) continue;
            for(int offset = 0; offset < 4; offset++){
                int new_row = S.first[0] + row_offset[offset];
                int new_col = S.first[1] + col_offset[offset];
                int count = 0;
                while (new_row >=0 && new_row < maze.size() && new_col >= 0 && new_col < maze[0].size() && maze[new_row][new_col] == 0){
                    new_row += row_offset[offset];
                    new_col += col_offset[offset];
                    count += 1;
                }
                if(distance[S.first[0]][S.first[1]] + count < distance[new_row - row_offset[offset]][new_col - col_offset[offset]]){
                    distance[new_row - row_offset[offset]][new_col - col_offset[offset]] = distance[S.first[0]][S.first[1]] + count;
                    min_heap.push(make_pair(vector<int>({new_row - row_offset[offset], new_col - col_offset[offset]}), distance[new_row - row_offset[offset]][new_col - col_offset[offset]]) );
                }
            }
        }
    }

    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        vector<vector<int>> distance(maze.size(), vector<int>(maze[0].size(), INT_MAX));
        vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));
        distance[start[0]][start[1]] = 0;
        Dijkstra(maze, start, distance);
        return distance[destination[0]][destination[1]] == INT_MAX ? -1 : distance[destination[0]][destination[1]];
    }
};
