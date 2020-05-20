/*
Maintain a sorted bank of all sums recorded, iterating row by row. At each row, discard sums that are positioned after k in the sort order (they will not help us find the answer). At the end, just take the last entry in the sorted order of k smallest sums that remains.
 */

class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        
        //Start with base sums, all numbers in the first row
        vector<int> sums = mat[0];
        
        //Iterating over the remaining rows
        for(int i = 1; i < mat.size(); i++) {
            
            //Store all the sums that result because of the new row and sort least to greatest
            vector<int> newsums;
            for(int j = 0; j < mat[i].size(); j++) 
                for(auto& s : sums)
                    newsums.push_back(mat[i][j] + s);
            sort(begin(newsums),end(newsums));
            
            //The current newsums are still running sums because iteration over all the rows is not complete
            //Discard all of the sums in the ordering that are after position k--as we keep adding row values they will get bigger and remain obsolete
            //Later row additions will make some of the current relevant new sums obsolete in a later iteration
            int sums_needed = min(k,int(newsums.size()));
            sums.resize(sums_needed);
            for(int l = 0; l < sums_needed ; l++)
                sums[l] = newsums[l];
        }
        
        //We are left with the final k sums sorted least to greatest
        return sums.back();
    }
};
