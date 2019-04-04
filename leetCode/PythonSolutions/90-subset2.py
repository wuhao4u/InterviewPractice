class Solution:
    def subsetsWithDup(self, nums):
        if not nums or len(nums) == 0:
            return []

        nums = sorted(nums)
        results = []
        self.recur(nums, [], 0, results)

        return results

    def recur(self, nums, soFar, startIndex, results):
        results.append(soFar.copy())

        for i in range(startIndex, len(nums)):
            if i != startIndex and nums[i] == nums[i - 1]:
                continue
            soFar.append(nums[i])
            self.recur(nums, soFar, i + 1, results)
            soFar.pop()
