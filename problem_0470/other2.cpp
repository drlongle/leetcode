class Solution {
public:
    int rand10() {
        int x = rand7();   // ----> Determines to choose from [1-5] or [6-10]
        while(x==7){   // redo the selection while the chosen number is 7.
            x = rand7(); // The number with equal chances will be either even (2,4,6) or odd (1,3,5). Note that 7 is excluded
        }
        int r1_5 = rand7();  // In here I generate a number between 1 and 5
        while(r1_5>5){  // redo if  >5
            r1_5 = rand7();
        }
        return r1_5 + (x%2)*5; // return the number getting help from x%2.
    }
};
