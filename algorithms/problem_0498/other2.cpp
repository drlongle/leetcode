class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> rez;
        if(matrix.empty()) return rez;
        int row = matrix.size(), col = matrix[0].size(), y = 0, x = 0;
        int n = row*col - 1;

        rez.push_back(matrix[0][0]);

        while (n) {
            if(x + 1 != col) {  //first shift
                x++; rez.push_back(matrix[y][x]); n--;
            } else if(y + 1 != row) {
                y++; rez.push_back(matrix[y][x]); n--;
            }

            while(true) { //first diagonal pass
                if(x - 1 >= 0 && y + 1 < row) {
                    x--,y++ ;rez.push_back(matrix[y][x]); n--;
                } else
                    break;
            }

            if(y + 1 != row) { //second shift
                y++; rez.push_back(matrix[y][x]); n--;
            }
            else if(x + 1 != col) {
                x++; rez.push_back(matrix[y][x]); n--;
            }

            while(true) { //second diagonal pass
                if(x + 1 < col && y -1 >= 0) {
                    x++,y-- ;rez.push_back(matrix[y][x]); n--;
                } else
                    break;
            }
        }

        return rez;
    }
};
