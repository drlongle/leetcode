/*
Fenwick tree

To learn more about Fenwick Tree

https://www.youtube.com/watch?v=CWDQJGaN1gY
https://www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/
*/

class Solution {
public:
    int N;
    vector<int> fen;
    vector<int> processQueries(vector<int>& queries, int m) {
        N=2*m;
        fen=vector<int>(2*m+1);
        vector<int> res;
        int idx=m;
        vector<int> valtoidx(m+1);
        for(int i=1;i<=m;i++){
            valtoidx[i]=idx++;
        }
        for(int i=m;i<=2*m-1;i++){
            add(i,1);
        }
        int newidx=m-1;
        for(int q:queries){
            int cnt=get(valtoidx[q]);
            res.push_back(cnt-1);
            add(valtoidx[q],-1);
            valtoidx[q]=newidx;
            add(newidx,1);
            newidx--;
        }
        return res;
    }
    
    int get(int index){
        index++;
        int res=0;
        while(index>=1){
            res+=fen[index];
            index-=index&(-index);
        }
        return res;
    }
    
    void add(int index, int val){
        index++;
        while(index<=N){
            fen[index]+=val;
            index+=index&(-index);
        }
    }
};
