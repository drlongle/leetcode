class Solution {
    public int maximalRectangle(char[][] matrix) {
        if(matrix.length==0) return 0;
        if(matrix[0].length==0) return 0;
        for(int j=0;j<matrix[0].length;j++) matrix[0][j] -= 48;
        for(int i=1;i<matrix.length;i++){
            for(int j=0;j<matrix[0].length;j++){
                if(matrix[i][j]!='0') matrix[i][j] += matrix[i-1][j]-48;
                // iterate over the matrix, and sum the columns for all values preceding a value up to the last 0
                else matrix[i][j]-=48; // - 48 because '0' is 48, etc.
            } 
        }
        int maxArea = 0;
        for(int i=0;i<matrix.length;i++){
            for(int j=0;j<matrix[0].length;j++){
                int r = j;
                int l = j;
                while(l>0 && matrix[i][j]<=matrix[i][l-1]) l--;
                while(r<matrix[i].length-1 && matrix[i][j]<=matrix[i][r+1]) r++;
                // check how many columns in the same row have a value greater than or equal to this value
                // this gives us the area
                int area = matrix[i][j]*(r-l+1);
                maxArea = (area>maxArea) ? area:maxArea;
            }
        } 
        /**
        // UNCOMMENT THIS SECTION TO SEE DYNAMICALLY ALTERED MATRIX
        /
        for(char[] row:matrix){
            System.out.print("\n"); 
            for(int n:row){
                String s = n+" ";
                System.out.print(String.format("%6s", s));
            }
        }
        /**
        */
        return maxArea;
    }
}

