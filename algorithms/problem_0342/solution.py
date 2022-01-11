class Solution:
    def isPowerOfFour(self, num: int) -> bool:
        i = 0
        while True:
            if 4**i == num:
                return True
            elif 4**i > num:
                break
            i += 1
        return False
