class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int l[] = {0,0,0,0};
        for(int i=obstacles.size()-2; i>0 ; i--){

            int nl[] = {0,0,0,0};

            l[obstacles[i+1]] = 500001;
            l[obstacles[i]] = 500001;

            nl[1] = min(l[1], min(l[2]+1, l[3]+1));
            nl[2] = min(l[2], min(l[1]+1, l[3]+1));
            nl[3] = min(l[3], min(l[2]+1, l[1]+1));
            copy(begin(nl),end(nl),begin(l));
        }

        return min(l[2], min(l[1]+1, l[3]+1));

    }
};
