public int candy(int[] ratings) {
        int[] candies = new int[ratings.length];
        Arrays.fill(candies,1); // Distribute one candy to each student
        
        //Now go from left to right and check if n student has more rating than n-1 student
        
        for(int i=1; i< ratings.length; i++){
            if(ratings[i] > ratings[i-1]){
                candies[i] = candies[i-1] + 1;
            }
        }
        
        
        //Now go from right to left and check if n student has more rating than n+1 student;
        
        for(int i = ratings.length-2; i>=0; i--){
            if(ratings[i] > ratings[i+1]){
                candies[i] = Math.max(candies[i+1] + 1, candies[i]);// if already got candies is MAX than new candies
            }
        }
        
        int totalCandies =0;
        for(int i=0; i<candies.length; i++){
            totalCandies += candies[i];
        }
        
        return totalCandies;
    }
}

