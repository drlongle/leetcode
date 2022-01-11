/*
minimumEffortPath is a binary search for the lowest effort that will work.
Only things special here are a ternary operator controlling which boundary is modified, and setting the
first midpoint to 415000, the median effort required, which probably actually wasted time.

The pathfinding function, canComplete, returns whether the given effort budget is enough to complete the maze.
It uses the wall-follower maze algorithm: follow the right wall until it reaches the end or the start.
I haven't seen anyone else use it in the discussions.
In terms of strategy, it's similar to a depth-first search that always checks the result of turning right
first, but it's more efficient because:

It it only checks squares on a region's boundary. When a right-turning DFS fails, it pointlessly checks every
square in the region.

It uses constant memory; specifically, 7 ints. It doesn't track a large vector of visited squares, since it
can only loop around at one location, (0, 0), and it doesn't need a stack.

It's largely self explanatory. The reason the false return's condition doesn't need to check the column is
left as an exercise for the reader.

getRotated simply uses "&3" as a cheap "%4" that always returns a positive value.

moveThatWay interprets a direction as a pair of bools that tells it whether to modify the row or column and
how to modify it. I encourage you to trace through it.
 */

enum direction{Left=0, Up=1, Right=2, Down=3};
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int highestBad = -1, lowestGood = 1000000, midpoint = 415000; 						/* int 1, 2, 3 */
        while(highestBad + 1 < lowestGood){
            (canComplete(heights, midpoint) ? lowestGood : highestBad) = midpoint;
            midpoint = (highestBad + lowestGood)/2;
        }
        return lowestGood;
    }
    bool canComplete(vector<vector<int>>& heights, int budget){
        direction facing = Right; 															/* Counting this as int 4 */
        int row = 0, col = 0, goalRow = heights.size()-1, goalCol = heights[0].size()-1; 	/* int 5-8 */
        while(true) {
            int newRow = row, newCol = col; 												/* int 9, 10 */
            moveThatWay(newRow, newCol, (facing = getRotated(facing, +1)));
            if(!(newRow < 0 || newCol < 0 || newRow > goalRow || newCol > goalCol ||
                 abs(heights[row][col]-heights[newRow][newCol]) > budget))//right is in bounds and in budget
                moveThatWay(row, col, facing);
            else facing = getRotated(facing, -2);//movement step over
            if(row == goalRow && col == goalCol) return true;
            if(row == 0 && facing == Left) return false;//looped back
        }
    }
    direction getRotated(direction start, int turn){ return static_cast<direction>((start+turn)&3);}
    void moveThatWay(int& row, int& col, direction way){ ((way&1) ? row : col) += ((way&2) ? +1 : -1); }
};
