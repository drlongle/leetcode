// Binary search

class Solution {
    public int findSpecialInteger(int[] arr) {
        int size = arr.length/4 + 1;
        int  i = 0, j =0;
		
        while(i<arr.length){
            j = size - 1 + binarySearch(arr[i], arr);
            if(j < arr.length && arr[j] == arr[i]) return arr[i];
            i += size;
        }
        return 0;
    }
    
    int binarySearch(int key, int[] arr){  
        int left = 0, right = arr.length-1, mid =0;
        
        while(left < right){
            mid = (left + right)/2;
            if(arr[mid]>= key){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return left;
    }
}
