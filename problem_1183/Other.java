class Solution {
    public int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
        int[][] sq = new int[sideLength][sideLength];
        for(int i = 0; i < height; i++) {
            for(int j = 0; j < width; j++) {
                sq[i % sideLength][j % sideLength]++;
            }
        }
        Queue<Integer> priorityQueue = new PriorityQueue<>((a1, a2)-> {
            return a2 - a1;
        });
        for(int i = 0; i < sideLength; i++) {
            for(int j = 0; j < sideLength; j++) {
                priorityQueue.add(sq[i][j]);
            }
        }
        
        
        int total = 0;
        for(int i = 0; i < maxOnes; i++) {
            total += priorityQueue.poll();
        }
        
        return total;
    }
}
