class Solution:
    def closestKValues(self, root: TreeNode, target: float, k: int) -> List[int]:
        def inorder(r: TreeNode):
            return inorder(r.left) + [r.val] + inorder(r.right) if r else []
        
        nums = inorder(root)
        nums.sort(key = lambda x: abs(x - target))
        return nums[:k]
