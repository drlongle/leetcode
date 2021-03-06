/*
Take care of Z, so moving UP and LEFT first, then RIGHT and DOWN later.
*/

class Solution {
public:
    unordered_map<char,vector<int>> mymap;
    string alphabetBoardPath(string target) {
        build_map(); // build alphabet location map
        int index = 0, row = 0, col = 0;
        string res = "";
        while(index < target.size())
            res += goNext(row,col,target[index++]); //append string by each char movement
        return res;
    }
    void build_map(){
        int row = 0, col = 0;
        for(char C = 'a' ; C <= 'z' ; C++,col++){
            if(col == 5)
                col = 0, row++;
            mymap[C].push_back(row),mymap[C].push_back(col);
        }
    }
    string goNext(int &r, int &c, char C){
        string tmp = "";
        while(mymap[C][1] < c) tmp += 'L',c--; //going LEFT
        while(mymap[C][0] < r) tmp += 'U',r--; //going UP
        while(mymap[C][0] > r) tmp += 'D',r++; //going DOWN
        while(mymap[C][1] > c) tmp += 'R',c++; //going RIGHT
        return tmp+'!';
    }
};
