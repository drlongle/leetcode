class Solution:
    def shortestPath(self, grid: List[List[int]], k: int) -> int:
        m, n = len(grid), len(grid[0])
        start = m-1, n-1, k
        queue = [(0, start)]
        seen = {start}
        for steps, (i, j, k) in queue:
        
        # This means we can just walk through all blocks
            if k >= i + j - 1:
                return steps + i + j
        
            for i, j in (i+1, j), (i-1, j), (i, j+1), (i, j-1):
                if m > i >= 0 <= j < n:
                    state = i, j, k - grid[i][j]
                    if state not in seen and state[2] >= 0:
                        queue.append((steps + 1, state))
                        seen.add(state)
        return -1
