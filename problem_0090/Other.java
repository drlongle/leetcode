class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Set<List<Integer>> powerSet = new HashSet<>();
        int n = (int)Math.pow(2, nums.length);
        
        int i = 0;
        
        while(i < n){
            int j = 0;
            List<Integer> subset = new ArrayList<>();
            int temp = i;
            
            while(j < n){
                int pos = temp&1;
                
                if(pos == 1){
                    subset.add(nums[j]);
                    //System.out.print(nums[j]+" ");
                }
                j++;
                
                temp = temp>>1;
            }
            
            Collections.sort(subset);
            //System.out.println();
            powerSet.add(subset);
            
            i++;
        }
        
        return new ArrayList(powerSet);
    }
}

