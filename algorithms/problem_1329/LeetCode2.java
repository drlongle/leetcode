class Solution {
    int[][] mat;
    int n, m;
    
    // Sort the current diagonal
    public void sortDiagonal(int i, int j) {
        // max heap -> to keep max element always on top
        Queue<Integer> diagonal = new PriorityQueue<>((o1, o2) -> o2 - o1);
        
        // store the current diagonal 
        // in the heap
        while (i < n && j < m) {
            diagonal.add(mat[i][j]);
            ++i;
            ++j;    
        }

        // push the sorted values 
        // back into the matrix
        while (i > 0 && j > 0) {
            --i;
            --j;
            mat[i][j] = diagonal.remove();    
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
