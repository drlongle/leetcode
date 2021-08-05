class Solution {
public:
    string pushDominoes(string dominoes) {
        int l = -1, itrl = -1;
        for(int i = 0;i<dominoes.length();i++){
            while(i<dominoes.length() && dominoes[i]=='.') i++;
            if(i==dominoes.length()) break;
            if(dominoes[i]=='L'){
                if(l==1) for(int j = 1;j<=(i-itrl-1)/2;j++)
                    dominoes[itrl+j] = 'R', dominoes[i-j] = 'L';
                else for(int j = itrl+1;j<i;j++) dominoes[j] = 'L';
                itrl = i, l = -1;
            }
            else{
                if(l==1) for(int j = itrl+1;j<i;j++) dominoes[j] = 'R';
                itrl = i, l = 1;
            }
        }
        if(itrl<dominoes.length()-1 && l==1)
            for(int j = itrl+1;j<dominoes.length();j++)
                dominoes[j] = 'R';
            return dominoes;
    }
};
