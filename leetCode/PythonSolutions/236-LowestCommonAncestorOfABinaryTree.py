# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class ReturnType:
    def __init__(self, has_p, has_q, val):
        self.has_p = has_p
        self.has_q = has_q
        self.val = val


class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if not root:
            return None

        res = self.helper(root, p, q)
        return res.val

    def helper(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> "ReturnType":
        if not root:
            return ReturnType(False, False, None)

        l_res = self.helper(root.left, p, q)
        r_res = self.helper(root.right, p, q)

        if l_res.has_p and l_res.has_q:
            return l_res
        elif r_res.has_p and r_res.has_q:
            return r_res

        has_p = has_q = False
        if l_res.has_p or r_res.has_p or root.val == p.val:
            has_p = True

        if l_res.has_q or r_res.has_q or root.val == q.val:
            has_q = True

        if has_p and has_q:
            return ReturnType(True, True, root.val)
        else:
            return ReturnType(has_p, has_q, None)


# if __name__ == '__main__':

