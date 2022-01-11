/*
Collect the max continue empty counts:
1. side seats -> left , right
2. between seats
*/

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        // get continue empty counts
        int maxEmpty = 0;
        int leftEmpty = 0;
        int rightEmpty = 0;
        int temp = 0;
        int index = 0;
        bool left = false;
        bool right = false;

        while (index < seats.size()) {
            left = false;
            right = false;
            temp = 0;

            if(seats[index] == 1){
                index++;
                continue;
            }

            while (index < seats.size() && seats[index] == 0){
                if(index == seats.size()-1){
                    right = true;
                }
                if(index == 0){
                    left = true;
                }

                temp++;
                index++;
            }

            if(temp > maxEmpty){
                maxEmpty = temp;
            }

            if(left){
                leftEmpty = temp;
            }

            if(right){
                rightEmpty = temp;
            }
        }

        int sideEmpty = max(leftEmpty, rightEmpty);
        int betweenEmpty = (maxEmpty+1)/2;

        return max(sideEmpty, betweenEmpty);

    }
};
