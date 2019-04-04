class Solution:
    def twoSum(self, nums, target):
        if nums is None or len(nums) == 0:
            return []

        res = [-1, -1]

        d = {}
        index = 0
        for n in nums:
            d[n] = index
            index += 1

        index = 0
        for n in nums:
            needed = target - n
            if needed in d.keys() and d[needed] != index:
                return [index, d[needed]]
            index += 1

        return res


if __name__ == '__main__':
    l1 = [1, 3, 4, 6, 7, 9]
    solution = Solution()
    print(solution.twoSum(l1, 10))
