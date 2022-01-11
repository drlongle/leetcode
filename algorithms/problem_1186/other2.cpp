class Solution {
public:

int maximumSum(vector<int> &arr) {
   int max_sum = arr[0];
   int subsum_without_deletion = arr[0];
   int subsum_with_deletion = 0;
   int deletion_num = arr[0];
   int len = 1;
  
   for(int i = 1; i< arr.size(); i++) {
     if(subsum_without_deletion >= 0) {
       subsum_without_deletion += arr[i];
       len++;
     }  
     else {
       subsum_without_deletion = arr[i];
       len = 1;
     }
     if(arr[i] > deletion_num) 
       subsum_with_deletion += arr[i];
     else {
       subsum_with_deletion += deletion_num;
       deletion_num = arr[i];
     }
     if(len > 1 && subsum_without_deletion - arr[i] > subsum_with_deletion) {
       subsum_with_deletion = subsum_without_deletion - arr[i];  
       deletion_num = arr[i];
     }
     max_sum = max(max_sum, subsum_with_deletion);
     if(len < arr.size())
       max_sum = max(max_sum, subsum_without_deletion);
  }
  return max_sum;
 }        
};
