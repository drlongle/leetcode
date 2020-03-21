// check left and top segments first

class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        int size = mines.size();
        if (N==1) return (1-size);
        if (size==0) return ((N+1)/2);

        // convert list of mine locations to data grid
        vector<vector<bool>> grid(N,vector<bool>(N,true));
        for (int i=0 ; i<size ; i++) {
            grid[mines[i][0]][mines[i][1]] = false;
        }
        int result = 0;
        if (size<N*N) result = 1;
        // initialize space to store top segment for every horizontal position
        vector<int> height(N,0);
        for (int i=0 ; i<N ; i++) {
            // initialize space to store left segment for every horizontal position
            vector<int> length(N,0);
            if (grid[i][0]==true) length[0]=1;
            for (int j=1 ; j<N ; j++) {
                if (grid[i][j]==true)
                    length[j] = length[j-1]+1;
                else
                    length[j] = 0;
            }
            for (int j=0 ; j<N ; j++) {
                if (grid[i][j]==true) {
                    height[j]++;
                    // check right segment if top and left segments are larger than current best
                    int newplus = min(length[j],height[j]);
                    if (newplus>result) {
                        int right = N-1;
                        int target = 2*(N-j);
                        // adjust for case that new cross goes beyond right boundary
                        if (newplus>result && j+newplus-1<N) {                        
                            right = j+newplus-1;
                            target = 2*newplus-1;
                        }
                        // if left segment equals to min of right and top, then no need to check one-by-one
                        if (newplus>result && length[right]<target) {
                            int k = j;
                            while (k<right && length[k]>0) k++;
                            newplus = min(newplus,(k-j));
                        }
                        else if (newplus>result)
                            newplus = min(newplus,(N-j));
                        // check bottom segment if top, left and right segments are larger than current best
                        if (newplus>result) {
                            int k = i+1;
                            while (k<N && k<i+newplus && grid[k][j]==true) k++;
                            newplus = min(newplus,(k-i));
                            if (newplus>result) {                         
                                result = newplus;
                            }
                        }
                    }
                }
                else {
                    height[j]=0;
                }
            }
        }
        return result;
    }
};
