/*
To understand what happen during the greedy arrangement, you only need to consider three cases.

Let's suppose n = 2.

Case 1. There are more than n kinds of tasks that have the largest number of instances.

"AAAABBBBCCCCDD"

In this case, there will never be a idle time slot, because it takes more than n step for you to choose the same task again. So the answer is the total number of the tasks.

Note that there are 3 kinds of tasks have the largest number of instances in the beginning, and after 6 steps, there will be 4 kinds of tasks. Therefore, the time interval between the same tasks you choose will only increase, which makes it impossible for idle time slots to appear.

Case 2. There are less than n kinds of tasks that have the largest number of instances, and there are only few other tasks.

"AAAABBBBCC"

The greedy arrangement will be "ABCABCAB_AB"

You can see that the main issue is that even though some kinds of tasks are all done, we need idle time slots in order to finish those tasks with higher frequency.

We can see from the case that the time that we need to finish those tasks having the largest number of instances is "(max_val - 1) * (n + 1) + max_cnt". And actually, we don't need to care about which time slot is idle. We only need to know the total time is "(max_val - 1) * (n + 1) + max_cnt" if the CPU ever idled.

Case 3. There are less than n kinds of tasks that have the largest number of instances, and there are MANY other tasks.

"AAAABBBBCCDDEEFF"

The greedy arrangement will be "ABCABDABEFABCDEF"

From case 2, we already know that there are at least "(max_val - 1) * (n + 1) + max_cnt" time slots to use. And in case 3 is what happens if all the time slots are filled and there are still tasks remain.

You can see two properties of the arrangement. First, there might be some "extra" task inserted to the expected "(max_val - 1) * (n + 1) + max_cnt" time slots. For example, the first F. Second, there might be some tasks remained after the expected "(max_val - 1) * (n + 1) + max_cnt" time slots, and all of them are non-repeated. (Since the tasks require more time slots are NOT those having the largest number of instances.) Becase nothing is repeated, the remaining tasks can be done without cooldown.

As a result, there is no cooldown in Case 3. The answer is the total number of the tasks.

 */
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int counter[26] = {0};
        for(char &c:tasks){
            counter[c - 'A']++;
        }
        int max_val = 0;
        for(int &v: counter){
            max_val = max(v, max_val);
        }
        int max_cnt = 0;
        for(int &v: counter){
            if(v == max_val) max_cnt++;
        }
        return max((int)tasks.size(), (max_val - 1) * (n + 1) + max_cnt);
    }
};
