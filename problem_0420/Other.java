/*
Repeating sequences like aaa with len % 3 == 0, we replace by deleting one character. For any repeating sequences aaaa with len % 3 == 1, we can reduce one replacement by deleting two character. For the rest, reduce every replacement by deleting three character.
*/

public class Solution {
    public int strongPasswordChecker(String s) {
        
        char [] str = s.toCharArray();
        boolean isUpper = false, isLower = false, isDigit = false;
        int missinType = 3;
        for(char c: str)
        {
            if(!isUpper && Character.isUpperCase(c)) { isUpper = true; missinType-=1; } //uppercase
            if(!isLower && Character.isLowerCase(c)) { isLower = true; missinType-=1; } //lowercase
            if(!isDigit && Character.isDigit(c)) { isDigit = true; missinType-=1; } //atleast one number
            
        }
       
        int totalChangeCnt = 0, OneChangeCnt =0, TwoChangeCnt =0, pos=2;
        while(pos < s.length())
        {
            if(str[pos]==str[pos-1] && str[pos-1]==str[pos-2] && str[pos-2]==str[pos])
            {
                int length = 2;
                while(pos < s.length() && str[pos]==str[pos-1])
                {
                    length += 1; pos +=1;
                }
                totalChangeCnt += length/3;
                if(length%3==0) OneChangeCnt += 1;
                else if(length%3==1) TwoChangeCnt += 1;
                
            }
            else
            {
                pos=pos+1;
            }
        }
        
        if(s.length()<6)
            return Math.max(missinType, 6-s.length());
        else if(s.length() <=20)
            return Math.max(missinType,totalChangeCnt );
        else
        {
            int deleteCount = s.length()-20;
            totalChangeCnt -= Math.min(deleteCount,OneChangeCnt*1)/1;
            totalChangeCnt -= Math.min(Math.max(deleteCount - OneChangeCnt, 0), TwoChangeCnt * 2) / 2;
            totalChangeCnt -= Math.max(deleteCount - OneChangeCnt - 2 * TwoChangeCnt, 0) / 3;

            return deleteCount + Math.max(missinType, totalChangeCnt);
        }
    }
}

