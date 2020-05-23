class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26,0);
        int i;
        int size = tasks.size(), intervals = 0;
        for(i = 0; i < size; i++){
            count[tasks[i] - 'A']++;
        }
        sort(count.begin(), count.end());
        //we will create slots where each slot will have different activities so that cooling period is utilized as much as possible
        // if there is no different tasks, we will fill the slot with idle time
        //number of slots required to keep similar task in different slots will be 
        //maximum occuring task that will be at count[25] after sorting - 1 because we need not to worry about last exection cooling;
        int noOfSlots = count[25] - 1;
        int noOfIdleSlots = noOfSlots * n;
        //noOfIdleSlots is the gap to be filled with other tasks or idle state of the processor for eg :  A_ _ A _ _ A(if A is maxM occuring then remaining blank space will be filled with B C etc tasks or idle )
        for( i = 24 ; i >= 0; i--){
            if(count[i] == 0) break;
            noOfIdleSlots -= (min(count[i], noOfSlots));
            //in case a tasks occurs as many time as max task then we again need not to worry about last time it will get executed
        }
        return noOfIdleSlots > 0 ? noOfIdleSlots + tasks.size() : tasks.size();
    }
};
