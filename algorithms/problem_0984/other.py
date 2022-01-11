class Solution(object):
    def strWithout3a3b(self, A, B):
        """
        :type A: int
        :type B: int
        :rtype: str
        """
        if A + B <= 3:
            return 'a' * A + 'b' * B
        if A > B:
            return 'aab' + self.strWithout3a3b(A-2,B-1) 
        elif B > A:
            return 'bba' + self.strWithout3a3b(A-1,B-2)
        else:    
            return 'ab' + self.strWithout3a3b(A-1,B-1)
