class Solution:
    def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
        n, m = len(mat), len(mat[0])
        
        def sort_diagonal(i, j):
            """
            Sort the current diagonal
            """
            diagonal = []
            # store the current diagonal 
            # in the heap
            while i < n and j < m:
                # max heap -> to keep max element always on top
                heappush(diagonal, -mat[i][j])
                i += 1
                j += 1
            
            # push the sorted values 
            # back into the matrix
            while i > 0 and j > 0:
                i -= 1
                j -= 1
                mat[i][j] = -heappop(diagonal)
                
        # sort all diagonals 
        # in the lower left corner
        for i in range(n): 
            sort_diagonal(i, 0)
        # sort all diagonals 
        # in the upper right corner
        for j in range(m): 
            sort_diagonal(0, j)
            
        return mat
