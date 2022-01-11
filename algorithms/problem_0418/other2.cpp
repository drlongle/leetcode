class Solution {
    unordered_map<int, pair<int,int>> memo; // each row: starting with index , how many repeat it generates? and last value of pos?
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        // current index to sentence to be filled.
        int pos=0;
        int repeat=0;
        for (int  i=0; i<rows; i++)
        {
            int col_pos=0; // each row, reset col_pos to 0
            // try to put current word into current row
            // two situations: first word (pos==0)  cols-col_pos
            // vs. later word
            if (memo.count(pos))
            {
                repeat+= memo[pos].first;
                pos = memo[pos].second;
                continue;
            }

            int orig_pos =pos;
            int count=0;
            do
            {
                while ( (col_pos<cols)
                        && (pos< sentence.size())
                        //  for 2nd and later word, must +1 for space
                        && ((cols-col_pos) >= ((sentence[pos].size()) + (col_pos!=0?1:0)) )
                        )
                {
                    // put the word
                    // 2nd and later word, add a space between previous and later word
                    if (col_pos!=0) col_pos++;
                    col_pos+=sentence[pos].size();
                    pos++;
                }

                // now col_pos == cols or
                //  no more space left  or
                // pos== sentence.size()
                if (pos==sentence.size())     // reaching the end, reset , add repeat
                {
                    repeat++; count++;
                    pos=0;
                }
                else if (cols-col_pos < sentence[pos].size() + (col_pos!=0?1:0) )
                {  // not enough space to fit next word, go to next row
                    break;
                }

            } while (col_pos<cols);

            memo[orig_pos]={count, pos};

        } // end row

        return repeat;
    }
};
