import sys


class Solution:
    def kadane(self, nums):
        dp = [0] * len(nums)
        answer = 0 - sys.maxsize

        dp[0] = nums[0]
        for i in range(1, len(nums)):
            dp[i] = max(dp[i - 1], 0) + nums[i]
            answer = max(answer, dp[i])

        return answer

    # Brute-force
    def maxSubArray(self, nums):
        if not nums or len(nums) == 0:
            return 0

        if len(nums) == 1:
            return nums[0]

        i = j = 0

        result = curMax = 0 - sys.maxsize
        while i < len(nums):
            curMax = 0
            j = i
            while j < len(nums):
                curMax += nums[j]
                result = max(result, curMax)
                j += 1
            i += 1

        return result


if __name__ == '__main__':
    l1 = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
    l2 = [-2, 1]
    l3 = [1]
    solution = Solution()
    print(solution.kadane(l1))
    print(solution.maxSubArray(l1))

    print(solution.kadane(l2))
    print(solution.maxSubArray(l2))

    print(solution.kadane(l3))
    print(solution.maxSubArray(l3))
