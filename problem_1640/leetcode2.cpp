class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int n = arr.size();
        int pLen = pieces.size();
        sort(pieces.begin(), pieces.end());

        int i = 0;
        while (i < n) {
            int found = -1;
            int left = 0;
            int right = pLen - 1;
            // use binary search to find target piece
            while (left <= right) {
                int mid = (left + right) / 2;
                if (pieces[mid][0] == arr[i]) {
                    found = mid;
                    break;
                } else if (pieces[mid][0] > arr[i]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            if (found == -1) {
                return false;
            }
            // check target piece
            auto targetPiece = pieces[found];
            for (int x : targetPiece) {
                if (x != arr[i]) {
                    return false;
                }
                i++;
            }
        }
        return true;
    }
};