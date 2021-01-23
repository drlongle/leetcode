class Solution {
    public int[][] diagonalSort(int[][] mat) {
        // hashmap to keep the diagonals
        HashMap<Integer, PriorityQueue<Integer>> h = new HashMap<>();
        
        // fill the hashmap
        int n = mat.length, m = mat[0].length;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) { 
                h.putIfAbsent(i - j, new PriorityQueue<>());
                h.get(i - j).add(mat[i][j]);
            }   
        }

        // build output
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                mat[i][j] = h.get(i - j).poll();
            }
        }
        
        return mat;
    }
}
