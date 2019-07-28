class Solution:
    def findLHS(self, nums) -> int:
        import collections
        if not nums:
            return 0

        result = 0
        c = collections.Counter(nums)

        for num in nums:
            if num + 1 in c:
                result = max(result, c[num] + c[num+1])

        return result


    def findLHS1(self, nums) -> int:
        if not nums:
            return 0

        result = 0

        d = {}

        for num in nums:
            d[num] = nums.count(num)

        for k in d.keys():
            total = d[k]

            if k + 1 in d:
                total += d[k + 1]

            result = max(result, total)

        return result


if __name__ == '__main__':
    a1 = [1, 1, 1, 1]
    solution = Solution()
    print(solution.findLHS(a1))
