class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int left[seats.size()];
        int last=-1;
        for (int i=0;i<seats.size();i++) {
            if (seats[i] == 1) {
                left[i] = last;
                last = i;
            } else {
                left[i] = last;
            }
        }
        last = -1;
        int maxDistance = -1;
        for (int i=seats.size() -1;i>=0;i--) {
            if (seats[i] == 0) {
                if (left[i] == -1) maxDistance = max(maxDistance,last - i);
                else if (last == -1) maxDistance = max(maxDistance,i - left[i]);
                else maxDistance = max(maxDistance,min(i-left[i],last -i));
            } else {
                last = i;
            }
        }

        return maxDistance ;
    }
};
