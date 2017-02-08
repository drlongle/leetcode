/*
68. Text Justification

    Total Accepted: 40233
    Total Submissions: 234226
    Difficulty: Hard

Given an array of words and a length L, format the text such that each line has
exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as
you can in each line. Pad extra spaces ' ' when necessary so that each line has
exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the
number of spaces on a line do not divide evenly between words, the empty slots
on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is
inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]

Note: Each word is guaranteed not to exceed L in length.
Corner Cases:
    A line other than the last line might contain only one word. What should you
    do in this case? In this case, that line should be left-justified.
 */

import java.io.*;
import java.util.*;

public class Solution
{
    void addLine(List<String> line, int length, int maxWidth)
    {
        StringBuilder sb = new StringBuilder();
        int spaceCount = maxWidth - length;
        if (line.size() == 1)
        {
            sb.append(line.get(0));
            String emptySpaces = new String(spaces, 0, spaceCount);
            sb.append(emptySpaces);
        }
        else
        {
            int spaceCount1 = spaceCount / (line.size() - 1);
            int remainSpaces = spaceCount % (line.size() - 1);
            String leftEmptySpaces = new String(spaces, 0, spaceCount1+1);
            String rightEmptySpaces = new String(spaces, 0, spaceCount1);
            for (int j = 0; j < line.size(); ++j)
            {
                sb.append(line.get(j));
                if (j < line.size() - 1)
                    sb.append((j < remainSpaces) ?
                        leftEmptySpaces : rightEmptySpaces);
            }
        }

        result.add(sb.toString());
    }
    
    public List<String> fullJustify(String[] words, int maxWidth)
    {
        result = new ArrayList<>();
        if (maxWidth == 0)
        {
            result.add(new String());
            return result;
        }

        List<String> currentLine = new ArrayList<>();
        int currentLength = 0;
        spaces = new char[maxWidth];
        Arrays.fill(spaces, ' ');
        String oneSpace = new String(spaces, 0, 1);

        for (int i = 0; i < words.length; ++i)
        {
            String word = words[i];
            int wordLength = word.length();
            if (currentLine.size() + currentLength + wordLength <= maxWidth)
            {
                currentLine.add(word);
                currentLength += wordLength;
            }
            else
            {
                addLine(currentLine, currentLength, maxWidth);
                currentLine.clear();
                currentLine.add(word);
                currentLength = wordLength;
            }
        }

        if (currentLine.size() > 0)
        {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < currentLine.size(); ++i)
            {
                sb.append(currentLine.get(i));
                if (i < currentLine.size() - 1)
                    sb.append(oneSpace);
            }
            if (sb.length() < maxWidth)
                sb.append(new String(spaces, 0, maxWidth - sb.length()));
            result.add(sb.toString());
        }

        return result;
    }

    private List<String> result;
    private char[] spaces;
    
    public static void main(String[] args) {
        Solution sol = new Solution();
        List<String> res;
        String[] words;
        int maxWidth;

        words = new String[] {"This", "is", "an", "example", "of", "text",
                               "justification."};
        maxWidth = 16;

        res = sol.fullJustify(words, maxWidth);
        res.forEach(s -> System.out.println(s));
    }
}
