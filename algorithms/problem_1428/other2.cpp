class Solution  {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        int n = binaryMatrix.dimensions()[0];
        int m = binaryMatrix.dimensions()[1];
		
        //go as much left as you can, and then go downwards.
        int check = m-1;
        for(int i = 0;i<n;i++){
            while(check>=0 and binaryMatrix.get(i,check)==1){
                check--;
            }
        }
        return (check==m-1)?-1:check+1;
    }
};
