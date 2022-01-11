# You can put '+' or '-' to remove the '| |', so there are 8 situations. As indicated by other post, you can further simplify to 4 cases.

class Solution(object):
    def maxAbsValExpr(self, arr1, arr2):
        """
        :type arr1: List[int]
        :type arr2: List[int]
        :rtype: int
        """
        n = len(arr1)
        nums1 = [arr1[i] + arr2[i] + i for i in range(n)]
        nums2 = [arr1[i] + arr2[i] - i for i in range(n)]
        nums3 = [arr1[i] - arr2[i] + i for i in range(n)]
        nums4 = [arr1[i] - arr2[i] - i for i in range(n)]
        nums5 = [-arr1[i] + arr2[i]  + i for i in range(n)]
        nums6 = [-arr1[i] + arr2[i]  - i for i in range(n)]
        nums7 = [-arr1[i] - arr2[i]  + i for i in range(n)]
        nums8 = [-arr1[i] - arr2[i]  - i for i in range(n)]
        
        def helper(nums):
            # nums.sort()
            # return nums[-1] - nums[0]
            return max(nums) - min(nums)
            
        return max(helper(nums1), helper(nums2),helper(nums3),helper(nums4),helper(nums5),helper(nums6),helper(nums7),helper(nums8))
