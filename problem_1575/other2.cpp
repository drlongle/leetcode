/*

The idea is: When you move, you either move rightward (to a city of larger location number) or leftward (to a city
of smaller location number). So, we sort the locations first and accordingly modify the "start" and "finish" first.
Then we define Ldp(j,f) to be the number of methods to move from start to j using exactly f fuels, while the last
move is toward left. Rdp(j,f) is similarly but the last move is toward right. (Under module, of course.)
Let's consider Ldp(j,f). Since your last move is toward left, you must move toward right to k first, where k>j,
and then keep moving toward left to j. When you move from k to j, you can choose whether to stay at city l
for each j<l<k, so there are 2^(k-j-1) ways to keep moving toward left from k to j. Therefore we have
Ldp(j,f)=Rdp(j+1,f-d(j,j+1))+2Rdp(j+2,f-d(j,j+2))+4Rdp(j+3,f-d(j,j+3))+...,
where d(i,j) is the distance between city i and j.

We also note that
Ldp(j+1,f)=Rdp(j+2,f-d(j+1,j+2))+2Rdp(j+3,f-d(j+1,j+3))+...
and then it happens to be
Ldp(j,f)=Rdp(j+1,f-d(j,j+1))+2Ldp(j+1,f-d(j,j+1)).
Similarly,
Rdp(j,f)=Ldp(j-1,f-d(j,j-1))+2Rdp(j-1,f-d(j,j-1)).

Now the dp costs only O(N* fuel). There remains some edge cases.
*/

class Solution {
    const int N=1000000007;

public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        start=locations[start];
        finish=locations[finish];
        sort(locations.begin(),locations.end());
        start=find(locations.begin(),locations.end(),start)-locations.begin();
        finish=find(locations.begin(),locations.end(),finish)-locations.begin();
        int size=locations.size();
        int j,f,d;
        vector<vector<int>> Ldp(size,vector<int>(fuel+1,0));
        vector<vector<int>> Rdp(size,vector<int>(fuel+1,0));
        for(f=1;f<=fuel;f++){
            Ldp[size-1][f]=0;
            Rdp[0][f]=0;
            for(j=0;j<size-1;j++){
                d=locations[j+1]-locations[j];
                if(f>d)
                    Ldp[j][f]=(Rdp[j+1][f-d]+2*Ldp[j+1][f-d]%N)%N;
                else
                    Ldp[j][f]=1*(f==d)*(start==(j+1));
            }
            for(j=1;j<size;j++){
                d=locations[j]-locations[j-1];
                if(f>d)
                    Rdp[j][f]=(Ldp[j-1][f-d]+2*Rdp[j-1][f-d]%N)%N;
                else
                    Rdp[j][f]=1*(f==d)*(start==(j-1));
            }
        }
        int ans=1*(start==finish);
        for(j=1;j<=fuel;j++) ans=((ans+Ldp[finish][j])%N+Rdp[finish][j])%N;
        return ans;
    }
};
