class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, inorder, postorder) -> TreeNode:
        def build(il, ir):
            if il > ir:
                return None

            root = TreeNode(postorder.pop())
            p = idx_map[root.val]

            root.right = build(p + 1, ir)
            root.left = build(il, p - 1)

            return root

        # build a hashmap value -> its index
        idx_map = {val: idx for idx, val in enumerate(inorder)}
        return build(0, len(inorder) - 1)


if __name__ == '__main__':
    inorder = [9, 3, 15, 20, 7]
    postorder = [9, 15, 7, 20, 3]
    # inorder = [1,3,2]
    # postorder = [3,2,1]
    solution = Solution()
    t = solution.buildTree(inorder, postorder)

