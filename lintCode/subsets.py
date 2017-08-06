class Solution:
    """
    @param S: The set of numbers.
    @return: A list of lists. See example.
    """
    def subsets(self, S):
        # write your code here
        i = 0
        self.pool = sorted(S)
        self.result = []
        self.subsets_recur(0, [])

        return self.result

    def subsets_recur(self, index, prefix):
        if index == len(self.pool):
            self.result.append(prefix)
            return

        # print prefix
        self.subsets_recur(index + 1, prefix)
        self.subsets_recur(index + 1, prefix + [self.pool[index]])

sol = Solution()
print(sol.subsets([1,2,3]))