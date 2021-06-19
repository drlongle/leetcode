class NumArray {
public:
    static const int n=1e5+5;
    int t[4*n];
    void update1(int v,int tl,int tr,int pos,int val){
        if(tl<=pos && pos<=tr){
            if(tl==pos && tr==pos){
                t[v] = val;
                return ;
            }

            int tm = (tl+tr)/2;
            update1(2*v,tl,tm,pos,val);
            update1(2*v+1,tm+1,tr,pos,val);
            t[v]=t[2*v]+t[2*v+1];
        }
        return ;

    }
    int query(int v,int tl,int tr,int l,int r){
        if(tl>r || tr<l){
            return 0;
        }

        if(l<=tl && tr<=r){
            return t[v];
        }

        int tm =(tl+tr)/2;
        int ans= query(2*v,tl,tm,l,r)+query(2*v+1,tm+1,tr,l,r);
        return ans;
    }

    NumArray(vector<int>& nums) {
        memset(t,0,sizeof(t));
        for(int i=0;i<nums.size();i++){
            update1(1,0,n-1,i,nums[i]);
        }
    }

    void update(int index, int val) {
        update1(1,0,n-1,index,val);
    }

    int sumRange(int left, int right) {
        return query(1,0,n-1,left,right);
    }
};
