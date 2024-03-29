class Solution {
  public:
    int flipLights(int n, int presses) {
        // Regardless how many n lightbulbs there are with initial state
        // ON=>only 1 state
        if (presses == 0)
            return 1;
        //[ flip all, flip odd, or flip 3k+1 ] is OFF.
        //[ flip even ] is ON
        if (n == 1)
            // Either this one lightbulb is ON or OFF after m=1 operations. Any
            // additional operations revert the lightbulb to a previous state
            if (presses >= 1)
                return 2;
        /*  0 0 ( after 1 operation: flip all )
            0 1 ( after 1 operation: flip odd or 3k+1 )
            1 0 ( after 1 operation: flip even )
         */
        if (n == 2) {
            if (presses == 1)
                return 3;
            /*
               00 or 01 or 10 or 11 possible
            */
            if (presses >= 2)
                return 4;
        }
        if (n >= 3) {
            // 000 or 010 or 011 or 101
            if (presses == 1)
                return 4;
            // 000 or 001 or 010 or 100 or 101 or 110 or 111
            if (presses == 2)
                return 7;
            // 000 or 001 or 010 or 011 or 100 or 101 or 110 or 111
            if (presses >= 3)
                return 8;
        }

        return 0;
    }
};
