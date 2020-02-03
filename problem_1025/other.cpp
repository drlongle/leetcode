class Solution {
public:
    bool divisorGame(int N) {
        //Alice can win only for even numbers
        return N%2 == 0;
    }
};
