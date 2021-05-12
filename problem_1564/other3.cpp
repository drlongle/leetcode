class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        int ret = 0;
        sort(boxes.begin(), boxes.end());
        vector<int> tunnel = warehouse;
        for(int i=1; i<warehouse.size(); i++){
            tunnel[i] = min(tunnel[i], tunnel[i-1]);
        }
        int ptr = tunnel.size()-1;
        for(int i=0; i<boxes.size(); i++){
            int flag = 0;
            while(ptr >= 0){
                if(tunnel[ptr] >= boxes[i]){
                    flag = 1;
                    ptr--;
                    break;
                }
                ptr--;
            }
            if(flag) ret++;
        }
        return ret;
    }
};
