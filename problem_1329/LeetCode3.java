class Solution {
    int[][] mat;
    int n, m;
    
    // Sort the current diagonal
    public void sortDiagonal(int i, int j) {
        List<Integer> diagonal = new ArrayList<>();
        // store the current diagonal 
        // in the list
        while (i < n && j < m) {
            diagonal.add(mat[i][j]);
            ++i;
            ++j;    
        }

        // sort the diagonal values
        Collections.sort(diagonal);

        // push the sorted values 
        // back into the matrix
        while (i > 0 && j > 0) {
            --i;
            --j;
            mat[i][j] = diagonal.remove(diagonal.size() - 1);    
        }
    }
    
    public int[][] diagonalSort(int[][] mat) {
        this.mat = mat;
        n = mat.length;
        m = mat[0].length;
                
        // sort all diagonals 
        // in the lower left corner
        for (int i = 0; i < n; ++i) {
            sortDiagonal(i, 0);       
        } 
        // sort all diagonals 
        // in the upper right corner
        for (int j = 0; j < m; ++j) {
            sortDiagonal(0, j);  
        } 
        return mat;
    }
}
