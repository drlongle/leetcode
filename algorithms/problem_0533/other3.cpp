class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        int n=picture.size();
        int m=picture[0].size();
        vector<int>row(n, 0);
        vector<int>col(m, 0);

        int pixels=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(picture[i][j]=='B'){
                    row[i]++;
                    col[j]++;
                }
            }
        }


        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(picture[i][j]=='B' && row[i]==N && (row[i]==col[j])){
                    bool rule2=true;
                    for(int k=0; k<n; k++){
                        if(picture[k][j]=='B' && picture[k]!=picture[i]){
                            rule2=false;
                        }
                    }
                    if(rule2)pixels++;
                }
            }
        }

        return pixels;
    }
};
