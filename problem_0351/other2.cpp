class Solution {
public:
    void calcPattern(int curr,int m,int n, int currLen, int &ans, int mid[10][10], bool visited[10])
    {
        if(currLen >= m) ans += 1;
        if(currLen >= n) return;

        visited[curr] = true; //don't do this if len>=n as it would return without making visited false

        for(int next=1; next <= 9; next++)
        {
            if(visited[next] == true) continue; //covers next==curr case
            int mustvisit = mid[next][curr];
            //if mid is adjacent (mid is 0 by default) or visited
            //every 2 nos that don’t need a mid are adjacent
            //eg: (1,2),(1,5),(1,8),(1,4) -> for (1,3),(1,7) need mid
            if(mustvisit == 0 || visited[mustvisit] == true)
            {
                calcPattern(next,m,n,currLen+1,ans,mid,visited);
            }
        }
        visited[curr]=false;
    }

    int numberOfPatterns(int m, int n) {
        int mid[10][10];
        bool visited[10];

        memset(mid,0,sizeof(mid[0][0])*10*10);
        memset(visited,false,sizeof(visited));

        mid[1][3] = mid[3][1] = 2; //2 is must visit for 1->3 or 3->1
        mid[1][7] = mid[7][1] = 4;
        mid[7][9] = mid[9][7] = 8;
        mid[3][9] = mid[9][3] = 6;
        mid[1][9]=mid[9][1]=mid[3][7]=mid[7][3]=mid[2][8]=mid[8][2]=mid[4][6]=mid[6][4]=5;

        int patternsCount = 0;
        int currResult = 0;
        calcPattern(1,m,n,1,currResult,mid,visited);
        patternsCount += currResult*4; //1,3,7,9

        currResult = 0;
        calcPattern(2,m,n,1,currResult,mid,visited);
        patternsCount += currResult*4; //2,4,6,8

        currResult = 0;
        calcPattern(5,m,n,1,currResult,mid,visited); //5
        patternsCount += currResult;

        return patternsCount;
    }
};
