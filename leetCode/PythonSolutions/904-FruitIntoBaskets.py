import collections


class Solution(object):
    def totalFruit(self, tree):
        ans = i = 0
        count = collections.Counter()
        for j, x in enumerate(tree):
            count[x] += 1

            # moving left pointer forward, if the counter is having > 2 distinct elements
            while len(count) >= 3:
                count[tree[i]] -= 1
                if count[tree[i]] == 0:
                    del count[tree[i]]
                i += 1
            ans = max(ans, j - i + 1)
        return ans


if __name__ == "__main__":
    sol = Solution()
    myInputs = [1, 2, 3, 2, 2]
    print(sol.totalFruit(myInputs))
