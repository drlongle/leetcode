from heapq import heappush, heappop
class Solution:
    def closestKValues(self, root: TreeNode, target: float, k: int) -> List[int]:
        def inorder(r: TreeNode):
            if not r:
                return
            
            inorder(r.left)
            heappush(heap, (- abs(r.val - target), r.val))
            if len(heap) > k:
                heappop(heap)
            inorder(r.right) 
    
        heap = []
        inorder(root)
        return [x for _, x in heap]
