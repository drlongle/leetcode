#check if current char is in a nested parenthesis, if it is, label it differently from previous

def maxDepthAfterSplit(self, seq):
    """
    :type seq: str
    :rtype: List[int]
    """
    res = [0]*len(seq)
    for i in xrange(1,len(seq)):
        if seq[i] != seq[i-1]:
            res[i] = res[i-1]
        else:
            if res[i-1] == 1:
                res[i] = 0
            else:
                res[i] = 1
        return res
