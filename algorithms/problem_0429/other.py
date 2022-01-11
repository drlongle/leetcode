class Solution:
    ans = []
    def levelTraverse(self, root, level):
        if (root is None):
            return
        if (level > len(self.ans)):
            self.ans.append([root.val])
        else:
            self.ans[level-1].append(root.val)
        for child in root.children:
            self.levelTraverse(child, level+1)
        return
        
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        if (root is None):
            return []
        self.ans = []
        self.levelTraverse(root, 1)
        return self.ans

