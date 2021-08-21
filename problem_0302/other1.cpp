class Solution {
public:
    const vector<string> direction = {"horizontal", "vertical"};

    int binarySearchLeftOrTop(vector<vector<char>>& image, int startIdx, int endIdx, int row, int col, string dir) {
        int mid = startIdx + (endIdx - startIdx) / 2;
        int result = mid;
        while (startIdx <= endIdx) {
            mid = startIdx + (endIdx - startIdx) / 2;
            if (hasBlack(image, mid, row, col, dir)) {
                result = mid;
                endIdx = mid - 1;
            }
            else {
                startIdx = mid + 1;
            }
        }
        return result;
    }

    int binarySearchRightOrBottom(vector<vector<char>>& image, int startIdx, int endIdx, int row, int col, string dir) {
        int mid = startIdx + (endIdx - startIdx) / 2;
        int result = mid;
        while (startIdx <= endIdx) {
            mid = startIdx + (endIdx - startIdx) / 2;
            if (hasBlack(image, mid, row, col, dir)) {
                result = mid;
                startIdx = mid + 1;
            }
            else {
                endIdx = mid - 1;
            }
        }
        return result;
    }

    bool hasBlack(vector<vector<char>>& image, int idx, int row, int col, string &dir) {
        if (dir == direction[0]) {
            for (int i = 0; i < row; i++) {
                if (image[i][idx] == '1') {
                    return true;
                }
            }
        }
        else {
            for (int j = 0; j < col; j++) {
                if (image[idx][j] == '1') {
                    return true;
                }
            }
        }
        return false;
    }

    int minArea(vector<vector<char>>& image, int x, int y) {
        int row    = image.size();
        int col    = image[0].size();
        int left   = binarySearchLeftOrTop     (image, 0, y, row, col, direction[0]);
        int right  = binarySearchRightOrBottom (image, y, col-1, row, col, direction[0]);
        int top    = binarySearchLeftOrTop     (image, 0, x, row, col, direction[1]);
        int bottom = binarySearchRightOrBottom (image, x, row-1, row, col, direction[1]);
        return (right - left + 1) * (bottom - top + 1);
    }
};
