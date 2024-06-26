from typing import List


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


# Runtime 180ms Beats 96.23%
# Memory 20.21 MB Beats 89.29%
class Solution:
    def balanceBST(self, root: TreeNode) -> TreeNode:
        nodes: List[TreeNode] = []
        
        def traverse(root: TreeNode):
            if not root: return    
            traverse(root.left)
            nodes.append(root)
            traverse(root.right)

        traverse(root)

        # divide and conquer
        def recursiveBalanceBST(start: int, end: int) -> TreeNode:
            if start >= end: 
                return None
            
            mid = start + (end - start) // 2

            root = nodes[mid]
            root.left = recursiveBalanceBST(start, mid)
            root.right = recursiveBalanceBST(mid+1, end)

            return root
        
        return recursiveBalanceBST(0, len(nodes))



# Runtime 186ms Beats 89.73%
# Memory 20.28 MBBeats 89.29%
class Solution1:
    def balanceBST(self, root: TreeNode) -> TreeNode:
        nodes: List[TreeNode] = []
        
        def traverse(root: TreeNode):
            if not root: return    
            traverse(root.left)
            nodes.append(root)
            traverse(root.right)

        traverse(root)

        # divide and conquer
        def recursiveBalanceBST(nodes: List[TreeNode]) -> TreeNode:
            n = len(nodes)

            if n == 0: return None
            if n == 1: 
                root = nodes[0]
                root.left = None
                root.right = None
                return root
            
            mid = n // 2
            root = nodes[mid]
            root.left = recursiveBalanceBST(nodes[0:mid])
            root.right = recursiveBalanceBST(nodes[mid+1:n])
            return root
        
        return recursiveBalanceBST(nodes)



if __name__ == '__main__':
    sol = Solution()
    root = TreeNode(1, None, TreeNode(2, None, TreeNode(3, None, TreeNode(4))))
    root = sol.balanceBST(root)
