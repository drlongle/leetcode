
/*
3. Longest Substring Without Repeating Characters

Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        const char* str = s.c_str();
        if (n == 0)
            return 0;
        int cur_len = 1;  // lenght of current substring
        int max_len = 1;  // result
        int prev_index;  //  previous index
        int i;
        int *visited = (int *)malloc(sizeof(int)*256);

        /* Initialize the visited array as -1, -1 is used to
           indicate that character has not been visited yet. */
        for (i = 0; i < 256;  i++)
            visited[i] = -1;
 
        /* Mark first character as visited by storing the index
           of first   character in visited array. */
        visited[str[0]] = 0;
 
        /* Start from the second character. First character is
           already processed (cur_len and max_len are initialized
           as 1, and visited[str[0]] is set */
        for (i = 1; i < n; i++)
        {
            prev_index =  visited[str[i]];
  
            /* If the currentt character is not present in the
               already processed substring or it is not part of
               the current NRCS, then do cur_len++ */
            if (prev_index == -1 || i - cur_len > prev_index)
                cur_len++;
 
            /* If the current character is present in currently
               considered NRCS, then update NRCS to start from
               the next character of previous instance. */
            else
            {
                /* Also, when we are changing the NRCS, we
                   should also check whether length of the
                   previous NRCS was greater than max_len or
                   not.*/
                if (cur_len > max_len)
                    max_len = cur_len;
 
                cur_len = i - prev_index;
            }
 
            // update the index of current character
            visited[str[i]] = i;
        }
 
        // Compare the length of last NRCS with max_len and
        // update max_len if needed
        if (cur_len > max_len)
            max_len = cur_len;
 
        free(visited); // free memory allocated for visited
        return max_len;
    }
};

int main()
{
    Solution solution;
    string s = "bdb";
    s = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!";
    cout << s << " --> " << solution.lengthOfLongestSubstring(s) << endl;
}

