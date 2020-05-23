class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
       if(!n) return tasks.size();
       int arr[(int)27] ;
       memset(arr , 0 , sizeof(arr) ) ;
       for(auto i : tasks)
       {
           ++arr[ i - 'A' ] ;
       }
        sort( arr  , arr + 26  ) ;
        int all_slots = ( arr[25] - 1 ) * n ;
        int val = arr[25] - 1 ; 
        for(int i = 24 ; i >= 0 ; i -- ){
            all_slots -= min(  val , arr[i] ) ; 
        }
        return (all_slots > 0 ) ? all_slots + tasks.size() : tasks.size() ;
    }
};
