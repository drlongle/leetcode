// Core idea is to use "counting sort" to find the median.

class Solution {
public:
    // this implementation exploits the idea of centroid
    int minTotalDistance(vector<vector<int>> &grid) {
        if (grid.empty() || grid.at(0).empty()) {
            return 0;
        }

        const int height = grid.size();
        const int width = grid.at(0).size();
        vector<int> hArray(height, 0);
        vector<int> wArray(width, 0);
        int count = 0;

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                if (grid.at(y).at(x) == 1) {
                    hArray.at(y) += 1;
                    wArray.at(x) += 1;

                    count++;
                }
            }
        }

        int threshold = (count % 2 == 0) ? (count / 2) : ((count + 1) / 2);
        int resultY = 0;
        int resultX = 0;

        int sum = 0;
        for (int h = 0; h < height; h++) {
            int afterSum = sum + hArray.at(h);

            if (afterSum < threshold) {
                sum = afterSum;
                continue;
            } else {
                resultY = h;
                break;
            }
        }

        sum = 0;
        for (int w = 0; w < width; w++) {
            int afterSum = sum + wArray.at(w);

            if (afterSum < threshold) {
                sum = afterSum;
                continue;
            } else {
                resultX = w;
                break;
            }
        }


        int distanceSum = 0;
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                if (grid.at(y).at(x) == 1) {
                    distanceSum += abs(resultX - x);
                    distanceSum += abs(resultY - y);
                }
            }
        }

        return distanceSum;
    }
};
